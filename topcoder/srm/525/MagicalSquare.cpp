#include <string>
#include <vector>

using namespace std;

typedef long long ll;
#define N 3
#define L 55

int match[N][N][L][L];

struct MagicalSquare
{
	ll getCount( vector<string> R, vector<string> C )
	{
		if( R[0].size()+R[1].size()+R[2].size() != C[0].size()+C[1].size()+C[2].size() ) return 0;
		for( int r = 0; r < 3; r++ ) for( int c = 0; c < 3; c++ )
		for( int i = R[r].size()-1; i >= 0; i-- ) for( int j = C[c].size()-1; j >= 0; j-- )
		if( R[r][i] == C[c][j] )
			match[r][c][i][j] = match[r][c][i+1][j+1] + 1;
		ll ans = 0;
		for( int a = 0; a <= match[0][0][0][0]; a++ )
		for( int b = 0; b <= match[0][1][a][0]; b++ )
		for( int c = 0; c <= match[1][0][0][a]; c++ )
		for( int d = 0; d <= match[1][1][c][b]; d++ )
		{
			int e = R[0].size()-a-b;
			int f = C[0].size()-a-c;
			int g = R[1].size()-c-d;
			int h = C[1].size()-b-d;
			int i = R[2].size()-f-h;
			if( match[0][2][a+b][0] == e )
			if( match[2][0][0][a+c] == f )
			if( match[1][2][c+d][e] == g )
			if( match[2][1][f][b+d] == h )
			if( match[2][2][f+h][e+g] == i )
				ans++;
		}
		return ans;
	}
};
