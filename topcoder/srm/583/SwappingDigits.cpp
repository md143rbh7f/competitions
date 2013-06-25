#include <algorithm>
#include <string>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int last[10];

struct SwappingDigits
{
	string minNumber( string s )
	{
		int n = s.size();
		rep(i,n) last[s[i]-'0'] = i;
		rep(i,n) REP(c,!i,s[i]-'0') if( last[c] > i )
		{
			swap( s[i], s[last[c]] );
			return s;
		}
		return s;
	}
};
