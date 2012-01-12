#include <string>

using namespace std;

string s;
long long mem[23][23];
char buf[23];

long long rec1( int n0, int n1 )
{
	long long & ans = mem[n0][n1];
	if( ans > -1 ) return ans;
	if( n0 + n1 == s.size() ) ans = 1;
	else
	{
		ans = 0;
		if( n0 < s.size()/2 && s[n0+n1] == buf[n0] ) ans += rec1( n0+1, n1 );
		if( n1 < s.size()/2 && s[n0+n1] == buf[n1] ) ans += rec1( n0, n1+1 );
	}
	return ans;
}

long long rec0( int n, int oc, int xc )
{
	if( n == s.size()/2 )
	{
		for( int i = 0; i <= s.size()/2; i++ )
		for( int j = 0; j <= s.size()/2; j++ )
			mem[i][j] = -1;
		return rec1( 0, 0 );
	}
	long long ans = 0;
	if( oc > 0 )
	{
		buf[n] = 'o';
		ans += rec0( n+1, oc-1, xc );
	}
	if( xc > 0 )
	{
		buf[n] = 'x';
		ans += rec0( n+1, oc, xc-1 );
	}
	return ans;
}

struct SPartition
{
	long long getCount( string _s )
	{
		s = _s;
		int oc = 0, xc = 0;
		for( int i = 0; i < s.size(); i++ )
		{
			if( s[i] == 'o' ) oc++;
			else if( s[i] == 'x' ) xc++;
		}
		if( oc % 2 || xc % 2 ) return 0;
		return rec0( 0, oc/2, xc/2 );
	}
};
