#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define _MAX(a, b) (a>b?a:b)
struct Edge{
	int v, c;
}; 
vector<Edge> m[40010];
int vis[40010], f, res;

void dfs(int u, int dis)
{
	vis[u] = 1;
	if(dis > res) {res = dis; f = u;}
	vector<Edge>::iterator it = m[u].begin();
	for(; it != m[u].end(); it++) 
		if(!vis[(*it).v])
			dfs((*it).v, dis+(*it).c);
}

int main()
{
	int N,M,u,v,c;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		scanf("%d%d%d %*c", &u, &v, &c);
		m[u].push_back({v, c});
		m[v].push_back({u, c});
	}
	memset(vis, 0 ,sizeof(vis));
	res = f = 0;
	dfs(1, 0);
	memset(vis, 0 ,sizeof(vis));
	res = 0;
	dfs(f ,0);
	cout << res << endl;
	return 0;
}
