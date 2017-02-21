#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1010;
const int inf = 1e9;
int n, m, k, e, p;
int head[25], next[maxn<<1], to[maxn<<1], dis[maxn<<1], cnt;
long long ok[25][110], cost[110][110], res[25], f[25];
bool can[25], vis[25];
void add(int a, int b, int c){
	next[++cnt] = head[a];
	head[a] = cnt;
	to[cnt] = b;
	dis[cnt] = c;
}
queue <int> q1;
int spfa(){
	while(!q1.empty()) q1.pop();
	for(int i = 0; i <= m; i ++) res[i] = inf, vis[i] = 0;
	q1.push(1), res[1] = 0;
	while(!q1.empty()){
		int x = q1.front();
		q1.pop(), vis[x] = 0;
		for(int i = head[x]; i; i = next[i]){
			if(!can[to[i]] && res[to[i]] > dis[i] + res[x]){
				res[to[i]] = dis[i] + res[x];
				if(vis[to[i]] == 0){
					q1.push(to[i]);
					vis[to[i]] = 1;
				}
			}
		}
	}
	return res[m];
}
int main(){
	scanf("%d%d%d%d", &n, &m, &k, &e);
	for(int i = 1; i <= e; i ++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), add(b, a, c);
	}
	scanf("%d", &p);
	for(int i = 1; i <= p; i ++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		ok[a][b] ++;
		ok[a][c+1] --;
	}
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			ok[i][j] += ok[i][j-1];
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++) cost[i][j] = inf;
		for(int j = 1; j <= m; j ++) can[j] = false;
		for(int j = i; j <= n; j ++){
			for(int k = 1; k <= m; k ++)
				if(ok[k][j] != 0) can[k] = true;
			cost[i][j] = spfa();
			if(cost[i][j] == inf) break;
		}
	}
	for(int i = 1; i <= m; i ++) f[i] = inf;
	for(int i = 1; i <= m; i ++){
		for(int j = 0; j < i; j ++){
			f[i] = min(f[i], f[j] + cost[j+1][i]*(i-j)+k);
		}
	}
	printf("%d", f[m]-k);
	return 0;
}
