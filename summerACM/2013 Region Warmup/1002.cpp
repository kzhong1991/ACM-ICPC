#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100010;
vector<int> map[MAX];
int N, D;
int cnt;

void dfs(int u, int pre, int dis)
{
	if(dis > D) return;
	cnt++;
	vector<int>::iterator it = map[u].begin();
	for(; it != map[u].end(); it++)
		if((*it) != pre) 
			dfs(*it, u, dis + 1);	
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &D);
		for(int i = 0; i < MAX; i++) map[i].clear();
		int u, v;
		for(int i = 0; i < N - 1; i++)
		{
			scanf("%d%d", &u, &v);
			map[u].push_back(v);
			map[v].push_back(u);
		} 
		cnt = 0;
		dfs(0, -1, 0);
		printf("%d\n", N - cnt);
	}
	return 0;
}
