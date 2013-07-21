//POJ 1952
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define _MAX(a, b) (a>b?a:b)
const int inf = 0x3f3f3f3f;

int main()
{
	int a[5010];
	int f[5010];
	int c[5010];
	int max = 0, N;
	cin >> N;
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	a[N+1] = -1;
	memset(f, 0, sizeof(f));
	memset(c, 0, sizeof(c));
	f[1] = 1;
	for(int i = 1; i <= N+1; i++) {
		max = 0;
		for(int j = i-1; j >= 1; j--)
			if(a[i] < a[j]) max = _MAX(f[j], max);
		f[i] = max + 1;
	}
	
	int t;
	for(int i = 1; i <= N+1; i++) {
		if(f[i] == 1){c[i] = 1; continue;}
		else c[i] = 0;
		for(int j = i-1; j >= 1; j--) {
			if(a[i] < a[j] && f[j] == f[i]-1){
				t=1;
				for(int k = j+1; k <= i-1; k++){
					if(a[k] == a[j]){t=0; break;}
				}
				if(t) c[i]+=c[j];
			}
		}
	}
	cout << f[N+1]-1 << " " << c[N+1] << endl;
	return 0;
}
