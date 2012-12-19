#include <vector>

using namespace std;

typedef long long ll;

#define B 30
#define MOD 1000000007

ll cnt[2], tmp[2];

struct DefectiveAddition
{
	int count( vector<int> c, int m )
	{
		int n = c.size();
		ll ans = 0;
		for( int b = 1<<B; b; b >>= 1 )
		{
			for( int i = 0; i < n; i++ ) if( c[i] & b )
			{
				cnt[0] = 1, cnt[1] = 0;
				for( int j = 0; j < n; j++ ) if( j != i )
				{
					if( c[j] & b )
					{
						for( int k = 0; k < 2; k++ )
							tmp[k] = ( cnt[k] * b + cnt[k^1] * ( c[j] - b + 1 ) ) % MOD;
						for( int k = 0; k < 2; k++ )
							cnt[k] = tmp[k];
					}
					else for( int k = 0; k < 2; k++ )
						cnt[k] = ( cnt[k] * ( c[j] + 1 ) ) % MOD;
				}
				ans = ( ans + cnt[(m&b)/b] ) % MOD, c[i] ^= b, m ^= b;
			}
			if( m & b ) break;
			if( b == 1 ) ans = ( ans + 1 ) % MOD;
		}
		return ans;
	}
};
