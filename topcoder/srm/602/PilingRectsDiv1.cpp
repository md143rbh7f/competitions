#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define acc(f,x,y) x=f(x,y)

#define INF 1234567890

struct PilingRectsDiv1
{
	ll getmax(int n, vi xs, vi ys, int xa, int xb, int xc, int ya, int yb, int yc)
	{
		int m = 2 * n;

		while(xs.size() < m)
		{
			xs.push_back(((ll) xs.back() * xa + xb) % xc + 1);
			ys.push_back(((ll) ys.back() * ya + yb) % yc + 1);
		}

		int x0 = INF, y0 = INF;
		rep(i, m)
		{
			if(xs[i] > ys[i]) swap(xs[i], ys[i]);
			acc(min, x0, xs[i]), acc(min, y0, ys[i]);
		}

		ll ans = 0;
		map<int, vi, greater<int>> by_x;
		rep(i, m) by_x[xs[i]].push_back(ys[i]);

		multiset<int> hi_y;
		for(auto & p : by_x)
		{
			for(auto & y : p.second) hi_y.insert(y);
			while(hi_y.size() > n) hi_y.erase(hi_y.begin());
			if(hi_y.size() == n)
				acc(max, ans, (ll) x0 * y0 + (ll) p.first * *hi_y.begin());
		}

		hi_y.clear();
		for(auto & y : ys) hi_y.insert(y);
		multiset<int> lo_y;
		for(auto & p : by_x)
		{
			for(auto & y : p.second) lo_y.insert(y), hi_y.erase(hi_y.find(y));
			while(lo_y.size() > n)
				hi_y.insert(*lo_y.rbegin()), lo_y.erase(lo_y.find(*lo_y.rbegin()));
			if(lo_y.size() == n)
				acc(max, ans, (ll) x0 * *hi_y.begin() + (ll) y0 * p.first);
		}

		return ans;
	}
};
