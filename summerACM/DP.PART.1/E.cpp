#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define _MAX(a, b) (a>b?a:b)
const int inf = 0x3f3f3f3f;
int f[100010], V;

void zeroOnePack(int c, int w)
{
	for(int i = V; i >= c; i--)
		f[i] = _MAX(f[i], f[i-c]+w);
}

void completePack(int c, int w)
{
	for(int i = c; i <= V; i++)
		f[i] = _MAX(f[i], f[i-c]+w);
}

void multiplePack(int c, int w, int n)
{
	if(c*n >= V){
		completePack(c, w);
		return;
	}
	int k = 1;
	while(n>k){
		zeroOnePack(k*c, k*w);
		n-=k;
		k*=2;
	}
	zeroOnePack(n*c, n*w);
}
int  main()
{
	int N;
	int n[11], w[11];
	while(scanf("%d%d", &V, &N) != EOF){
		for(int i=1; i<=N;i++) scanf("%d %d", &n[i], &w[i]); 
		memset(f, 0, sizeof(f));
		int max;
		for(int i=1; i<=N; i++)
			multiplePack(w[i], w[i], n[i]);
		cout << f[V]<< endl;
	}
	return 0;
}
