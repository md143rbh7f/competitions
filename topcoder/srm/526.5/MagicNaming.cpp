#include <string>

using namespace std;

int dp[55][55];

struct MagicNaming
{
	int maxReindeers( string name )
	{
		int n = name.size(), ans = 0;
		for( int a = 0; a < n; a++ ) dp[a][n] = 1;
		for( int a = n-2; a >= 0; a-- ) for( int b = a+1; b < n; b++ ) for( int c = b+1; c <= n; c++ ) if( dp[b][c] > 0 )
		{
			bool leq = true;
			int i = 0, j = b-a;
			for( int k = 0; k < c-a; k++ )
			{
				if( name[a+i] < name[a+j] ) break;
				if( name[a+i] > name[a+j] )
				{
					leq = false;
					break;
				}
				i = ( i + 1 ) % ( c - a );
				j = ( j + 1 ) % ( c - a );
			}
			if( leq && dp[b][c] + 1 > dp[a][b] ) dp[a][b] = dp[b][c] + 1;
		}
		for( int i = 1; i <= n; i++ ) if( dp[0][i] > ans ) ans = dp[0][i];
		return ans;
	}
};
