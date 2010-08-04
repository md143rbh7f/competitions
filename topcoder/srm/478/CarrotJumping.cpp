typedef long long ll;

int mod = 1000000007;

struct CarrotJumping
{
	int theJump( int init )
	{
		ll c = 4;
		for( int i = 2; i <= 300000; i++ )
		{
			ll test = (c*(ll)init+c-1)%mod;
			if( test==0 )
			{
				int lj = i/3, sj = 0;
				if( i%3==1 ) lj--, sj = 2;
				if( i%3==2 ) sj = 1;
				return lj+sj;
			}
			c = (c*2)%mod;
		}
		return -1;
	}
};
