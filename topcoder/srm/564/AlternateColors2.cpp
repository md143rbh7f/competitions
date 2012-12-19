typedef long long ll;

#define N 100005

ll c3[N], c2[N];

struct AlternateColors2
{
	ll countWays( int n, int k )
	{
		k--, c2[n] = c3[n] = 1;
		for( int i = n - 1; i >= 0; i-- )
		{
			c2[i] = i > k ? 2 : 1;
			if( i + 2 <= n && ( i + 2 <= k || i >= k ) ) c2[i] += c2[i+2];

			c3[i] = i > k ? 3 : 1;
			if( i + 2 <= n )
			{
				if( i > k ) c3[i] += 3 * c2[i+2];
				else if( i + 2 <= k || i == k ) c3[i] += 2 * c2[i+2];
			}
			if( i + 3 <= n && ( i + 3 <= k || i >= k ) ) c3[i] += c3[i+3];
		}
		return c3[0];
	}
};
