#include <string>
#include <vector>

using namespace std;

#define N 22
#define P 200005
#define Q 3

long long ways[1<<Q][P], dp[2][P], MOD = 1000000007;
int id[N];

struct SRMIntermissionPhase
{
	int countWays( vector<int> pts, vector<string> solved )
	{
		ways[0][0] = 1;
		for( int m = 1; m < 1<<Q; m++ ) for( int j = 0; j < Q; j++ ) if((m>>j)&1)
		{
			for( int p = 1; p < P; p++ )
			{
				ways[m][p] = ( ways[m][p-1] + ways[m-(1<<j)][p-1] ) % MOD;
				if( p > pts[j] )
					ways[m][p] = ( ways[m][p] - ways[m-(1<<j)][p-pts[j]-1] + MOD ) % MOD;
			}
			break;
		}

		int n = solved.size();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < Q; j++ ) if( solved[i][j] == 'Y' ) id[i] |= 1<<j;

		if(!id[n-1]) dp[(n-1)%2][0] = 1;
		for( int p = 1; p < P; p ++ ) dp[(n-1)%2][p] = ( dp[(n-1)%2][p-1] + ways[id[n-1]][p] ) % MOD;
		for( int i = n-2; i >= 0; i-- )
		{
			dp[i%2][0] = 0;
			for( int p = 1; p < P; p++ )
				dp[i%2][p] = ( dp[i%2][p-1] + ( ways[id[i]][p] * dp[(i+1)%2][p-1] ) % MOD ) % MOD;
		}

		return dp[0][P-1];
	}
};
