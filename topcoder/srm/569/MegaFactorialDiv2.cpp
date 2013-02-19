#define N 1005
#define MOD 1000000009

long long c[N];
bool p[N];

struct MegaFactorialDiv2
{
	int countDivisors( int n, int k )
	{
		for( int i = 0; i <= n; i++ ) c[i] = 1;
		for( int j = 1; j < k; j++ ) for( int i = 1; i <= n; i++ )
			c[i] = ( c[i-1] + c[i] ) % MOD;

		long long ans = 1;
		for( int i = 2; i <= n; i++ ) p[i] = true;
		for( int i = 2; i <= n; i++ ) if( p[i] )
		{
			long long cnt = 0;
			for( int j = i; j <= n; j += i )
			{
				p[j] = false;
				int e = 0, k = j;
				while( k % i == 0 ) k /= i, e++;
				cnt = ( cnt + c[n-j] * e ) % MOD;
			}
			ans = ( ans * ( 1 + cnt ) ) % MOD;
		}
		return ans;
	}
};
