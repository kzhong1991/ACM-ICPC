#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define _MAX(a, b) (a>b?a:b)
#define _MIN(a, b) (a<b?a:b)
#define _INF -0x3fffffff;

int main()
{
	int N, a[150010], ans = 0;
	int t = 1;
	cin >> N;
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= N; i++) {
		if(a[i] >= a[i-1] && a[i] >= a[i+1] && t) {
			ans+=a[i];
			t = 0;
		}
		else if(a[i] <= a[i-1] && a[i] <= a[i+1] && !t) {
			ans-=a[i];
			t = 1;
		}
	}

	cout << ans << endl;
	return 0;
}
