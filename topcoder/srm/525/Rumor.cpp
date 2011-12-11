#include <string>
#include <vector>

using namespace std;

typedef long long ll;
#define OVER_NINE_THOUSAND 9001
#define N 17

ll parent[2*N];

struct Rumor
{
	int getMinimum( string start_know, vector<string> g )
	{
		int n = g.size(), best = OVER_NINE_THOUSAND;

		ll start = 0;
		for( int i = 0; i < n; i++ ) if( start_know[i] == 'Y' ) start |= 3ll<<(2*i);

		for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
		if( g[i][j] == 'Y' )
		{
			parent[2*j] |= 1 << ( 2 * i );
			parent[2*j+1] |= 1 << ( 2 * i + 1 );
		}

		for( int p = 0; p < 1<<n; p++ )
		{
			ll cur = start;
			int dist = 0, policy = p;
			while(1)
			{
				ll tell = 0, next = cur;
				for( int i = 0; i < n; i++ )
				{
					int know = ( cur >> ( 2 * i ) ) & 3;
					if( know == 3 )
					{
						tell |= 1ll << ( 2 * i + ( ( policy >> i ) & 1 ) );
						policy ^= 1 << i;
					}
					else tell |= know << ( 2 * i );
				}
				for( int j = 0; j < n; j++ )
				for( int b = 0; b < 2; b++ )
				if( tell & parent[2*j+b] )
					next |= 1ll << ( 2 * j + b );
				if( next == cur ) break;
				dist++;
				cur = next;
			}
			if( cur == ( ( 1ll<< ( 2 * n ) ) - 1 ) && dist < best ) best = dist;
		}
		return best == OVER_NINE_THOUSAND ? -1 : best;
	}
};
