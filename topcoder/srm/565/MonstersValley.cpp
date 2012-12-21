#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

#define N 55

ll best[N][2*N];

struct MonstersValley
{
	int minimumPrice( vector<ll> u, vector<int> c )
	{
		memset( best, -1, sizeof(best) );
		int n = u.size();
		best[0][0] = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j <= 2 * i; j++ )
		if( best[i][j] > -1 )
		{
			if( best[i][j] >= u[i] )
				best[i+1][j] = max( best[i+1][j], best[i][j] );
			best[i+1][j+c[i]] = max( best[i+1][j+c[i]], best[i][j] + u[i] );
		}
		int ans = 0;
		while( best[n][ans] == -1 ) ans++;
		return ans;
	}
};
