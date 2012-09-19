#include <algorithm>
#include <string>

using namespace std;

#define N 55

int n;
string lo, digs, mem[N][N][3], BAD = "X";
bool seen[N][N][3];

int cmp( string & a, string & b )
{
	if( a < b ) return 0;
	if( a > b ) return 2;
	return 1;
}

string & rec( int i, int j, int flag )
{
	string & ans = mem[i][j][flag];
	if( seen[i][j][flag] ) return ans;

	seen[i][j][flag] = true;
	if( i == j ) return ans = "";

	char c = digs[j-i-1];
	string need = lo.substr( i, j - i ), l = BAD, r = BAD;
	for( int k = 0; k < 3; k++ )
	{
		string test = rec( i + 1, j, k );
		if( test != BAD )
		{
			test = c + test;
			if( cmp( test, need ) >= flag )
			{
				l = test;
				break;
			}
		}
	}
	for( int k = 0; k < 3; k++ )
	{
		string test = rec( i, j - 1, k );
		if( test != BAD )
		{
			test = test + c;
			if( cmp( test, need ) >= flag )
			{
				r = test;
				break;
			}
		}
	}

	if( l != BAD && r != BAD ) ans = min( l, r );
	else if( l != BAD ) ans = l;
	else if( r != BAD ) ans = r;
	else ans = BAD;
	
	return ans;
}

struct LeftRightDigitsGame2
{
	string minNumber( string _digs, string _lo )
	{
		digs = _digs, lo = _lo, n = digs.size();
		string ans = rec( 0, n, 1 );
		return ans != BAD ? ans : "";
	}
};
