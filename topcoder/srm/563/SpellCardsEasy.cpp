#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define N 55

int mem[N][N], n;
vector<int> lvl, dmg;

int rec( int i, int need )
{
	int & ans = mem[i][need];
	if( ans != -1 ) return ans;
	if( i + need == n ) return ans = 0;
	ans = rec( i + 1, max( 0, need - 1 ) );
	if( i + need + lvl[i] <= n ) ans = max( ans, dmg[i] + rec( i + 1, need + lvl[i] - 1 ) );
	return ans;
}

struct SpellCardsEasy
{
	int maxDamage( vector<int> _lvl, vector<int> _dmg )
	{
		lvl = _lvl, dmg = _dmg, n = lvl.size();
		memset( mem, -1, sizeof(mem) );
		return rec( 0, 0 );
	}
};
