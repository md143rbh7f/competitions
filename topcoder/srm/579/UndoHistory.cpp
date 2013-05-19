#include <set>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

string pre( string & s, int i )
{
	return s.substr( 0, i );
}

struct UndoHistory
{
	int minPresses( vs lines )
	{
		int ans = 0;
		string cur = "";
		set<string> prefixes;
		foreach( line, lines )
		{
			rep( i, cur.size() + 1 ) prefixes.insert( pre( cur, i ) );

			int best = 9001;
			for( int j = line->size(); j >= 0; j-- )
			if( prefixes.count( pre( *line, j ) ) )
			{
				best = 3 + line->size() - j;
				break;
			}

			if( cur.size() <= line->size() && cur == pre( *line, cur.size() ) )
				best = min( best, (int) ( line->size() - cur.size() + 1 ) );

			ans += best;
			cur = *line;
		}
		return ans;
	}
};
