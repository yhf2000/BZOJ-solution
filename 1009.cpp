#include <iostream>
#include <cstdio>
using namespace std;
int f[50], x[50], trans[50][15], mod, n, m, p, res;
char ch[50];
struct Matrix{
	int node[25][25];
	Matrix(){
		for(int i = 0; i <= 24; i ++) {
			for(int j = 0; j <= 24; j ++){
				node[i][j] = 0;
			}
		}
	}
	void init(){
		for(int i = 0; i <= m; i ++) node[i][i] = 1;
	}
	Matrix operator * (const Matrix &M){
		Matrix res;
		for(int i = 0; i < m; i ++)
			for(int j = 0; j < m; j ++)
				for(int k = 0; k < m; k ++)
					res.node[i][j] = (res.node[i][j] + node[i][k]*M.node[k][j]) % mod;
		return res;
	}
} w, ans, Begin;
Matrix pow(Matrix x, int y){
	Matrix res;
	res.init();
	for( ; y; y >>= 1, x = x*x) if(y&1) res = res * x;
	return res; 
}
int main(){
	scanf("%d%d%d", &n, &m, &mod);
	scanf("%s", ch+1);
	for(int i = 1; i <= m; i ++) x[i] = ch[i]-'0';
	p = 0;
	for(int i = 2; i <= m; i ++){
		while(p && x[p+1] != x[i]) p = f[p];
		if(x[p+1] == x[i]) p ++;
		f[i] = p;
	}
	for(int i = 0; i < m; i ++){
		for(int j = 0; j <= 9; j ++){
			p = i;
			while(p && x[p+1] != j) p = f[p];
			if(x[p+1] == j) p ++;
			trans[i][j] = p;
		}
	}
	for(int i = 0; i < m; i ++){
		for(int j = 0; j <= 9; j ++){
			if(trans[i][j] != m) w.node[i][trans[i][j]] ++;
		}
	}
	Begin.node[0][0] = 1;
	ans = pow(w, n);
	ans = Begin * ans;
	for(int i = 0; i < m; i ++){
		res = (res + ans.node[0][i]) % mod;
	}
	printf("%d", res);
	return 0;
}
