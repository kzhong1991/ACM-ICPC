#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int main()
{
	int T;
	int sum = 0;
	string str;
	cin >> T;
	while(T--)
	{
		cin >> str;
		if (str.size()==1)
		{
			cout<<("19")<<endl;
			continue;
		}
		int sum=0;
		int len=str.size()-2;
		for (int i=0;i<str.size();i++)
		{
			sum+=str[i]-'0';
			sum=sum%10;
		}

		if ('9'-str[str.size()-1]>=10-sum)
		{
			str[str.size()-1]=str[str.size()-1]+10-sum;
			cout<<str<<endl;
			continue;
		}
		int t=0;
		while (len>=0)
		{
			if (str[len]=='9')
			{
				t=1;
				str[len]='0';
				
			}else
			{
				str[len]=str[len]+1;
				t=0;
				break;
			}
			len--;
		}
		sum=t;
		for (int i=0;i<str.size()-1;i++)
			{
			sum+=str[i]-'0';
			sum=sum%10;
		}
		if (sum==0)
		str[str.size()-1]='0';
		else
		{
			
		str[str.size()-1]=10-sum+'0';
		}
		if (t==1) cout<<t;
		cout<<str<<endl;
	}
	return 0;
}
