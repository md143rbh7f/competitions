#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

struct WinterAndPresents
{
	ll getNumber(vi a, vi o)
	{
		int n = a.size(), m = a[0] + o[0];
		rep(i, n) m = min(m, a[i] + o[i]);
		ll ans = 0;
		range(c, 1, m + 1)
		{
			int x = 0, y = 0;
			rep(i, n) x += max(c - o[i], 0), y += min(c, a[i]);
			ans += y - x + 1;
		}
		return ans;
	}
};
