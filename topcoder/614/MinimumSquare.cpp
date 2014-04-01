#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

struct MinimumSquare
{
	ll minArea(vi xs, vi ys, int k)
	{
		int n = xs.size();
		ll ans = 1e11;
		for(auto x : xs) for(auto y : ys)
		{
			ll l = 0, r = 1e11;
			while(l < r)
			{
				ll m = (l + r) / 2;
				int cnt = 0;
				rep(i, n) cnt += x <= xs[i] && xs[i] <= x + m && y <= ys[i] && ys[i] <= y + m;
				if(cnt >= k) r = m;
				else l = m + 1;
			}
			ans = min(ans, l);
		}
		return (ans + 2) * (ans + 2);
	}
};
