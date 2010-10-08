typedef long long ll;

int cnt( ll x )
{
	int ans = 0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}

struct RabbitNumber
{
	int theCount( int a, int b )
	{
		int ans=0;
		for(int m=0;m<(1<<20);m++)
		{
			ll x=0;
			for(int i=1;i<(1<<20);i<<=2) x=x*10+((m/i)%4);
			if( x>=a && x<=b && cnt(x)*cnt(x)==cnt(x*x) ) ans++;
		}
		return ans;
	}
};
