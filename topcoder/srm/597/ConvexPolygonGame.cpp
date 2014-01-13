#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005

int _lo[2*N], *lo = _lo + N, _hi[2*N], *hi = _hi + N;

struct ConvexPolygonGame
{
	string winner(vi xs, vi ys)
	{
		int n = xs.size(), xl = N, xr = -N;
		for(auto x : xs) xl = min(xl, x), xr = max(xr, x);
		xs.push_back(xs[0]), ys.push_back(ys[0]);

		rep(i, n)
		{
			int x0 = xs[i], x1 = xs[i+1], dx = x1 - x0;
			if(!dx) continue;
			int y0 = ys[i], y1 = ys[i+1], dy = y1 - y0;
			int d = dx > 0 ? 1 : -1, *ans = dx > 0 ? lo : hi;
			bool round = (ll) dx * dy > 0;
			for(ll x = x0; x != x1 + d; x += d)
			{
				ll b = (x - x0) * dy;
				ans[x] = y0 + b / dx + (round && (b % dx)) * d;
			}
			ans[x0] += d, ans[x1] += d;
		}

		int x0, y0, cnt = 0;
		ll dx, dy;
		range(x, xl, xr + 1) range(y, lo[x], hi[x] + 1) switch(cnt)
		{
			case 0: x0 = x, y0 = y, cnt++; break;
			case 1: dx = x - x0, dy = y - y0, cnt++; break;
			case 2: if(dx * (y - y0) - dy * (x - x0)) return "Masha"; break;
		}
		return "Petya";
	}
};
