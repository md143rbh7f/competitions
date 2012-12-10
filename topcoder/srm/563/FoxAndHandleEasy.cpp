#include <string>

using namespace std;

struct FoxAndHandleEasy
{
	string isPossible( string s, string t )
	{
		int n = s.size(), m = t.size();
		if( 2 * n != m ) return "No";
		for( int i = 0; i <= n; i++ )
		if( t.substr( i, n ) == s
		&& t.substr( 0, i ) + t.substr( i + n, m - i ) == s )
			return "Yes";
		return "No";
	}
};
