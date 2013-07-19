#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int ans = 0, d = 0, time = 10;
	int t[100];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	sort(t, t+n);
	for(int i = 0; i < n; i++)
	{
		time+=t[i];
		if(time <= 360){
			ans++;
		}
		else if(time>360 && time <=720){
			ans++;
			d+=time-360;
		}
		else break;
	}
	cout << ans << " " << d << endl;	 
} 
