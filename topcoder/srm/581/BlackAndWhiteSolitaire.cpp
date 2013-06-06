#include <algorithm>
#include <string>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

struct BlackAndWhiteSolitaire
{
	int minimumTurns( string s )
	{
		int ans0 = 0, ans1 = 0;
		rep(i,s.size()) ( ( i % 2 ) ^ ( s[i] == 'W' ) ? ans0 : ans1 )++;
		return min( ans0, ans1 );
	}
};
