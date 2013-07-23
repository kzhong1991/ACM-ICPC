#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1e9+7
#include <vector>
using namespace std;
vector<int> *map;
int root=1;
int ma=0;
void dfs(int n,int pre,int ans)
{
	if (ans>ma){
		ma=ans;
		root=n;
	}
	int len=map[n].size();
	for (int i=0;i<len;i++)
	{
		if ( map[n][i]!=pre){	
			dfs(map[n][i],n,ans+1);
		}
	}
}
int main()
{
	int T;
	int a,b;
	cin>>T;
	while (T--)
	{
		int n,m;
		cin>>n>>m;
	//	for (int i=0;i<=n;i++) map[i].clear();
		map=new vector<int>[n+3];
		int k;
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			k=a;
			map[a].push_back(b);
			map[b].push_back(a);
		}
		ma=0;
		root=1;
		dfs(k,k,1);
		ma=0;
		dfs(root,root,1);
		for (int i=0;i<m;i++)
		{
			scanf("%d",&a);
			if (a<ma)
			{
				printf("%d\n",a-1);
				//cout<<a-1<<endl;
			}else
			{
				printf("%d\n",ma-1+(a-ma)*2);
				//cout<<ma-1+(a-ma)*2<<endl;
			}
			
		}
		delete map;
	}
	return 0;
}
