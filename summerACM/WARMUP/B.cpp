#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	int a[400][400], b[400], ans[400];
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	memset(ans, 0, sizeof(b));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; i <= n; j++)
		{
			int k;
			for(k = 1; b[k] > a[i][j] || b[k]==i; k++);
            if(b[k] == a[i][j]) {
                ans[i] = b[k];
                break;
            }
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(i != n)
			cout << ans[i] << " ";
		else cout << ans[i];
	}
}
