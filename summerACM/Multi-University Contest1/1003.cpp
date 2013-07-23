#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MOD=1000000007;
long long f[1000010];
long long  exp_mod(long long  a,long long n)
{
    long long t;
    if(n==0) return 1%MOD;
    if(n==1) return a%MOD;
    t=exp_mod(a,n/2);
    t=t*t%MOD;
    if((n&1)==1) t=t*a%MOD;
    return t;
}
int main()
{
	int T;
	cin>>T;
	f[0]=1;
	for (int i=1;i<1000010;i++) f[i]=f[i-1]*2 % MOD;
	while (T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		long long ans=0;
		if (n-k<2) {printf("%d\n",n-k+1); continue;}
		if (n-k-1<1000001){
		
			ans=(f[n-k-1]*2%MOD+(n-k-1)*f[n-k-2]%MOD)%MOD;
			if (ans<0) ans+=MOD;
		//cout<<ans%MOD<<endl;
		printf("%I64d\n",ans);
		}
		else
		{
			long long t=f[1000000];
			t=exp_mod(2,n-k-2);
			ans=(t*2*2%MOD+(n-k-1)*t%MOD)%MOD;
			if (ans<0) ans+=MOD;
		printf("%I64d\n",ans);
		}
	}
	return 0;
}
