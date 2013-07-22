#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int C, G;
	int c[22], w[22];
	int f[22][15010];
	cin >> C >> G;
	for(int i=1; i<=C; i++) scanf("%d", &c[i]);
	for(int i=1; i<=G; i++) scanf("%d", &w[i]);
	memset(f, 0, sizeof(f));
	for(int i=1; i<=C; i++) f[1][c[i]*w[1]+7500]++;
	for(int i=1; i<=G; i++)
		for(int j=1; j<=C; j++)
			for(int v=0; v<=15000; v++)
				if(f[i-1][v]) f[i][v+c[j]*w[i]]+=f[i-1][v];
	cout << f[G][7500] << endl;
	return 0;
}
