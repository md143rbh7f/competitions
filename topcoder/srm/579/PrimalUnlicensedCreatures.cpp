#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define all(i) (i).begin(),(i).end()

struct PrimalUnlicensedCreatures
{
	int maxWins( int p, vi q )
	{
		sort(all(q));
		int i = 0;
		for( ; i < q.size() && p > q[i]; i++ ) p += q[i] / 2;
		return i;
	}
};
