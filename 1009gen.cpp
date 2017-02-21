#include <bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	int m = (rand()%20) +1, n = 1e8+m+rand(), mod = 1000;
	printf("%d %d %d\n", n, m, mod);
	for(int i = 1; i <= m; i ++){
		printf("%c", '0'+(rand()%10));
	}
	return 0;
}
