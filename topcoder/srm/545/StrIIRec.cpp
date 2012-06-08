#include <cstring>
#include <string>

using namespace std;

int n;
char ans[30], min_str[30];
bool used[30];

bool rec( int pos, int need, bool lex )
{
	if( pos == n ) return need <= 0;
	int cnt = 0, rem = ( n - pos - 1 ) * ( n - pos - 2 ) / 2;
	for( char c = 'a'; c < 'a' + n; c++ ) if( !used[c-'a'] )
	{
		if( cnt + rem >= need && ( lex || c >= min_str[pos] ) )
		{
			ans[pos] = c;
			used[c-'a'] = true;
			if( rec( pos + 1, need - cnt, lex || c > min_str[pos] ) ) return true;
			used[c-'a'] = false;
		}
		cnt++;
	}
	return false;
}

struct StrIIRec
{
	string recovstr( int _n, int min_inv, string _min_str )
	{
		n = _n;
		strcpy( min_str, _min_str.c_str() );
		if( rec( 0, min_inv, false ) ) return string( ans, n );
		return "";
	}
};
