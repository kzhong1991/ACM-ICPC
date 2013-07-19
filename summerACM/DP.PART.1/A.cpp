#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define _MAX(a, b) (a>b?a:b)
#define _INF -0x3fffffff;

int main()
{
	int c[110][110];
	int f[110][110];
	int F, V;
	int max = 0;
	scanf("%d%d", &F, &V);
	for(int i = 1; i <= F; i++) 
		for(int j = 1; j <= V; j++) scanf("%d", &c[i][j]);
	memset(f, 0 ,sizeof(f));
	f[1][1] = c[1][1];
	for(int i = 1; i <= F; i++) f[i][0] = _INF;
	for(int i = 1; i <= F; i++)
		for(int j = 1; j <= V; j++)
			f[i][j] = _MAX(f[i][j-1], f[i-1][j-1] + c[i][j]);
	cout << f[F][V] << endl;
	return 0;
}
