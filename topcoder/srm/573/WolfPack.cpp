#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define M(x) ((x)%MOD)

#define N 100005
#define MOD 1000000007

int _bin[2 * N], * bin = _bin + N;

ll mod_pow(ll a, ll b)
{
	if(!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

ll mod_inv(int a)
{
	return mod_pow(a, MOD - 2);
}

ll work(vi & xs, int m)
{
	ll ans = 0;
	int x0 = *max_element(all(xs)) - m, x1 = *min_element(all(xs)) + m;
	range(x_, x0, x1 + 1)
	{
		ll cnt = 1;
		for(auto x : xs) cnt = M(cnt * bin[x - x_]);
		ans = M(ans + cnt);
	}
	return ans;
}

struct WolfPack
{
	int calc(vi x, vi y, int m)
	{
		ll choose = 1;
		rep(i, m + 1)
		{
			bin[2 * i - m] = choose;
			choose = M(choose * M((m - i) * mod_inv(i + 1)));
		}
		vi u, v;
		rep(i, x.size())
			u.push_back(x[i] + y[i]), v.push_back(x[i] - y[i]);
		return M(work(u, m) * work(v, m));
	}
};
