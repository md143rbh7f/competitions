#define min(a,b) ((a<b)?(a):(b))

typedef long long ll;

struct FoxMakingDice
{
	ll theCount( int N, int K )
	{
		ll ans=0;
		if(K<7) K=7;
		for(int k=K;k<=2*N-5;k++)
		{
			ll x=min((k-1)/2,(2*N-k+1)/2);
			ans+=x*(x-1)*(x-2)/3;
		}
		return ans;
	}
};
