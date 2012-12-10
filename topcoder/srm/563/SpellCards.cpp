#include <algorithm>
#include <vector>

using namespace std;

int best[55];

struct SpellCards
{
	int maxDamage( vector<int> lvl, vector<int> dmg )
	{
		int n = lvl.size(), ans = 0;
		for( int i = 0; i < n; i++ )
		for( int j = n; j - lvl[i] >= 0; j-- )
			best[j] = max( best[j], dmg[i] + best[ j - lvl[i] ] );
		for( int i = 0; i <= n; i++ )
			ans = max( ans, best[i] );
		return ans;
	}
};
