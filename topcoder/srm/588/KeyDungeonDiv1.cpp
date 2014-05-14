#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 12

set<pii> rgs[1<<N];

struct KeyDungeonDiv1
{
	int maxKeys(vi ar, vi ag, vi br, vi bg, vi bw, vi rgw)
	{
		int n = ar.size(), ans = 0;
		rep(i, rgw[2] + 1) rgs[0].insert({rgw[0] + i, rgw[1] + rgw[2] - i});
		rep(i, 1<<n) for(auto & rg : rgs[i])
		{
			int r = rg.first, g = rg.second;
			ans = max(ans, r + g);
			rep(j, n) if(!((i>>j)&1) && r >= ar[j] && g >= ag[j])
			{
				int k = i^(1<<j), rr = r - ar[j] + br[j], gg = g - ag[j] + bg[j];
				rep(l, bw[j] + 1) rgs[k].insert({rr + l, gg + bw[j] - l});
			}
		}
		return ans;
	}
};
