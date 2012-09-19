#include <algorithm>
#include <string>

using namespace std;

#define N 55

int n;
string digs, mem[N][N];

string & rec( int i, int j )
{
	string & ans = mem[i][j];
	if( ans.size() || i == j ) return ans;
	char c = digs[j-i-1];
	string l = c + rec( i + 1, j ), r = rec( i, j - 1 ) + c;
	if( i == 0 )
	{
		if( l[0] == '0' ) l = "X";
		if( r[0] == '0' ) r = "X";
	}
	return ans = min( l, r );
}

struct LeftRightDigitsGame
{
	string minNumber( string _digs )
	{
		digs = _digs;
		n = digs.size();
		return rec( 0, n );
	}
};
