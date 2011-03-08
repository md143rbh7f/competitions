#include <string>

using namespace std;

#define MAX 55
#define OVER_NINE_THOUSAND 9001

int dp[MAX][MAX];

struct MakeSquare
{
	int minChanges( string S )
	{
		int n = S.size(), ans = OVER_NINE_THOUSAND;
		if( n==1 ) return 1;
		for( int m = 1; m < n; m++ )
		{
			int l = n-m;
			for( int i = 0; i < MAX; i++ ) for( int j = 0; j < MAX; j++ ) dp[i][j] = 0;
			dp[0][0] = S[0] != S[m];
			for( int i = 0; i < m; i++ ) for( int j = 0; j < l; j++ )
			{
				if( i||j ) dp[i][j] = OVER_NINE_THOUSAND;
				if( i && j && dp[i-1][j-1] + ( S[i] != S[m+j] ) < dp[i][j] ) dp[i][j] = dp[i-1][j-1] + ( S[i] != S[m+j] );
				if( i && dp[i-1][j] + 1 < dp[i][j] ) dp[i][j] = dp[i-1][j] + 1;
				if( j && dp[i][j-1] + 1 < dp[i][j] ) dp[i][j] = dp[i][j-1] + 1;
			}
			if( dp[m-1][l-1] < ans ) ans = dp[m-1][l-1];
		}
		return ans;
	}
};
