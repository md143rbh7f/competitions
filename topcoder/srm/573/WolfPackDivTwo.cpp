#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define M(x) ((x)%MOD)

#define MOD 1000000007
#define S 55
#define buf(t, a) t _##a[4*S*S], (*a)[2*S] = (t (*)[2*S])(_##a + 2 * S * S + S)

buf(int, bin);
buf(int, tmp);

struct WolfPackDivTwo
{
	int calc(vi xs, vi ys, int m)
	{
		bin[0][0] = 1;
		rep(t, m)
		{
			range(x, -t, t + 1) range(y, -t, t + 1) if(bin[x][y])
			{
				tmp[x + 1][y] = M(bin[x][y] + tmp[x + 1][y]);
				tmp[x - 1][y] = M(bin[x][y] + tmp[x - 1][y]);
				tmp[x][y + 1] = M(bin[x][y] + tmp[x][y + 1]);
				tmp[x][y - 1] = M(bin[x][y] + tmp[x][y - 1]);
				bin[x][y] = 0;
			}
			swap(bin, tmp);
		}

		int n = xs.size(), x0 = -S, y0 = -S, x1 = 2 * S, y1 = 2 * S;
		for(auto x : xs) x0 = max(x0, x - m), x1 = min(x1, x + m);
		for(auto y : ys) y0 = max(y0, y - m), y1 = min(y1, y + m);

		ll ans = 0;
		range(x, x0, x1 + 1) range(y, y0, y1 + 1)
		{
			ll ways = 1;
			rep(i, n) ways = M(ways * bin[x - xs[i]][y - ys[i]]);
			ans = M(ans + ways);
		}
		return ans;
	}
};
