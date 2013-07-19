#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define _MAX(a, b) (a>b?a:b)
#define _MIN(a, b) (a<b?a:b)
#define _INF -0x3fffffff;
int f[2][5010];
int main()
{
	int N;
	char a[5010], b[5010];
	cin >> N;
	getchar();
	for(int i = 1; i <= N; i++) {
		scanf("%c", &a[i]);
		b[N+1-i] = a[i];
	}
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++) {
			if(a[i] == b[j])
				f[i%2][j] = f[(i-1)%2][j-1]+1;
			else		 
				f[i%2][j] = _MAX(f[i%2][j-1], f[(i-1)%2][j]);
		}
	
	cout << N-f[N%2][N] << endl;
	
	return 0;
}
