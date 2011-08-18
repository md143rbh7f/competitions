#include <string>
#include <vector>

using namespace std;

bool used[2][50];

bool win( char a, char b )
{
	return ( a == 'R' && b == 'S' ) || ( a == 'P' && b == 'R' ) || ( a == 'S' && b == 'P' );
}

struct DoubleRoshambo
{
	int maxScore( vector<string> a, vector<string> b )
	{
		int score = 0, n = a.size();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
		if( !used[0][i] && !used[1][j] && win( a[i][0], b[j][0] ) && win( a[i][1], b[j][1] ) )
		{
			used[0][i] = used[1][j] = true;
			score += 2;
		}
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
		if( !used[0][i] && !used[1][j] && a[i][0]==b[j][0] && win( a[i][1], b[j][1] ) )
		{
			used[0][i] = used[1][j] = true;
			score++;
		}
		return score;
	}
};
