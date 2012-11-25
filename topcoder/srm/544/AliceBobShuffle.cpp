#include <algorithm>
#include <vector>

using namespace std;

#define add(x) dp[i][j][k] = ( dp[i][j][k] + x ) % 1000000007
#define N 55

int dp[2*N][N][N];

struct AliceBobShuffle
{
	int countWays( vector<int> a0, vector<int> b0, vector<int> a1, vector<int> b1 )
	{
		int na0 = a0.size(), nb0 = b0.size(), na1 = a1.size(), nb1 = b1.size(), n = na0 + nb0;
		if( na1 + nb1 != n ) return 0;
		dp[0][0][0] = 1;
		for( int i = 1; i <= n; i++ )
		for( int j = max( 0, i - nb0 ); j <= min( i, na0 ); j++ )
		for( int k = max( 0, i - nb1 ); k <= min( i, na1 ); k++ )
		{
			if( j > 0 && k > 0 && a0[j-1] == a1[k-1] ) add( dp[i-1][j-1][k-1] );
			if( j > 0 && k < i && a0[j-1] == b1[i-k-1] ) add( dp[i-1][j-1][k] );
			if( j < i && k > 0 && b0[i-j-1] == a1[k-1] ) add( dp[i-1][j][k-1] );
			if( j < i && k < i && b0[i-j-1] == b1[i-k-1] ) add( dp[i-1][j][k] );
		}
		return dp[n][na0][na1];
	}
};
