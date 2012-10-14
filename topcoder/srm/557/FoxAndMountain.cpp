#include <string>

using namespace std;

#define add( x ) x = ( x + ways[i][j][k] ) % 1000000009
#define N 55

int ways[N][N][N], next[N][2];
char c[] = "DU";

struct FoxAndMountain
{
	int count( int n, string hist )
	{
		int m = hist.size();
		for( int i = 0; i < m; i++ ) for( int j = 0; j < 2; j++ )
		{
			string s = hist.substr( 0, i ) + c[j];
			for( int k = i + 1; k; k-- ) if( hist.substr( 0, k ) == s.substr( i + 1 - k, k ) )
			{
				next[i][j] = k;
				break;
			}
		}
		next[m][0] = next[m][1] = m, ways[0][0][0] = 1;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) for( int k = 0; k <= m; k++ )
		{
			add( ways[i+1][j+1][next[k][1]] );
			if( j > 0 ) add( ways[i+1][j-1][next[k][0]] );
		}
		return ways[n][0][m];
	}
};
