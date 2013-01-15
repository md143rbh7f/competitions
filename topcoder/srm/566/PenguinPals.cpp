#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string,int> mem;

struct PenguinPals
{
	int findMaximumMatching( string s )
	{
		if( mem.count(s) ) return mem[s];
		int & ans = mem[s];
		if( s == "" ) return ans;
		ans = max( ans, findMaximumMatching( s.substr( 1 ) ) );
		for( int i = 1; i < s.size(); i++ ) if( s[0] == s[i] )
			ans = max( ans, 1
			+ findMaximumMatching( s.substr( 1, i - 1 ) )
			+ findMaximumMatching( s.substr( i + 1 ) )
			);
		return ans;
	}
};
