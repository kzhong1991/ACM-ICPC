#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define _MAX(a, b) (a>b?a:b)
#define _MIN(a, b) (a<b?a:b)
#define _INF -0x3fffffff;

int main()
{
	int n;
	int a[200][200];
	int sum[200], ans[200];
	int max;
	cin >> n;
	memset(a, 0, sizeof(a));
	memset(sum, 0, sizeof(sum));
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	max = _INF;
	for(int i = 1; i <= n; i++)
		for(int j = i; j <=n; j++)
		{
			memset(sum, 0, sizeof(sum));
			memset(ans, 0, sizeof(ans));
			for(int k = 1; k <= n; k++)
				for(int p = i; p <= j; p++)
					sum[k] += a[p][k];
			for(int ix = 1; ix <= n; ix++) {
				ans[ix] = _MAX(sum[ix], ans[ix-1]+sum[ix]);
				if (max < ans[ix]) max = ans[ix];
			}
		}
	cout << max <<  endl;
	return 0;
}
