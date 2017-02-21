#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxm = 6000010, maxn = 2000010;
const int inf = 2e9;
struct point{
	int x, val;
	point(int _x, int _val){x = _x, val = _val;}
	bool operator < (const point &t)const{return val > t.val;} 
};
struct shortest_path{
	int head[maxn], next[maxm], to[maxm], dt[maxm];
	int dis[maxm], cnt, MX, S, T;
	bool vis[maxn];
	priority_queue <point> q;
	void add(int a, int b, int c){
		next[++cnt] = head[a];
		head[a] = cnt;
		to[cnt] = b;
		dt[cnt] = c;
	}
	int dij(){
		while(!q.empty()) q.pop();
		for(int i = 0; i <= MX; i ++) vis[i] = 0, dis[i] = inf;
		dis[S] = 0, q.push(point(S, dis[S]));
		while(!q.empty()){
			int x = q.top().x; q.pop();
			if(vis[x]) continue; vis[x] = 1;
			if(vis[T]) break;
			for(int i = head[x]; i; i = next[i])
				if(!vis[to[i]] && dis[x] + dt[i] < dis[to[i]]){
					dis[to[i]] = dis[x] + dt[i];
					q.push(point(to[i], dis[to[i]]));
				}
		}
		return dis[T];
	}
};

shortest_path P;
int main(){
	int 
	printf("%d", P.dij());
	return 0;
} 
