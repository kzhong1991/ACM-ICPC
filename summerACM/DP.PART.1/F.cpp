#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define _MAX(a, b) (a>b?a:b)
#define _MIN(a, b) (a<b?a:b)
const int inf = 0x3f3f3f3f;

int main()
{
	int N;
	double a[1010];
	int l[1010];
	int r[1010];
	cin >> N;
	for(int i=1; i<=N; i++) scanf("%f", &a[i]);
	int max;
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	for(int i=1; i<=N; i++){
		max = 0;
		l[i] = 1;
		for(int j=1; j<=i-1; j++)
			if(a[j] < a[i]) max = _MAX(max, l[j]+1);
		l[i] = _MAX(max, l[i]);
	}
	for(int i=N; i>=1; i--) {
		max = 0;
		r[i] = 1;
		for(int j=N; j>=i+1; j--)
			if(a[j] < a[i]) max = _MAX(max, r[j]+1);
		r[i] = _MAX(max, r[i]);
	}

	max = 0;
	for(int i = 1; i <= N-1; i++)
		for(int j = i+1; j <= N; j++)
			max = _MAX(max, l[i]+r[j]);
		
	cout << N-max << endl;
	return 0;
}
