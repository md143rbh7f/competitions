#include <algorithm>
#include <vector>

using namespace std;

#define N 55

int d[N*N], cnt[N];

struct KingdomAndDice
{
	double newFairness( vector<int> d0, vector<int> d1, int x )
	{
		int n = d0.size(), nn = n * n, m = 0, w = 0;
		for( int i = 0; i < n; i++ ) m += !d0[i];

		sort( d1.begin(), d1.end() );
		d1.push_back( x + 1 );
		for( int j = 0; j < n; j++ )
		{
			cnt[j] = d1[j+1] - d1[j] - 1;
			for( int i = 0; i < n; i++ ) if( d0[i] > d1[j] )
			{
				w++;
				if( d0[i] < d1[j+1] ) cnt[j]--;
			}
			cnt[j] = min( cnt[j], m );
		}

		for( int i = 1; i <= n * n; i++ ) d[i] = nn;
		for( int i = 0; i < n; i++ )
		for( int j = 0; j < cnt[i]; j++ )
		for( int k = nn; k > i; k-- )
			d[k] = min( d[k], d[k-i-1] + 1 );

		int best = -1;
		for( int i = 0; i <= nn; i++ )
		if( d[i] <= m && abs( 2 * ( w + i ) - nn ) < abs( 2 * best - nn ) )
			best = w + i;
		return 1.0 * best / nn;
	}
};
