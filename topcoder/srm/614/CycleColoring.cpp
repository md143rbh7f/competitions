#include <cstdlib>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

#define N 55
#define MOD 1000000007

ll k, ik, ik1;

ll mod_pow(ll a, ll b)
{
	if(!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

ll cycle(ll n)
{
	return M(M(M(mod_pow(k - 1, n) + (n % 2 ? -1 : 1) * (k - 1)) + MOD) * ik);
}

struct CycleColoring
{
	int countColorings(vi cnt, vi in, vi out, int _k)
	{
		int n = cnt.size();
		k = _k, ik = mod_pow(k, MOD - 2), ik1 = mod_pow(k - 1, MOD - 2);
		ll same = 1, diff = 0;
		rep(i, n)
		{
			int m = cnt[i], a = abs(in[i] - out[(i - 1 + n) % n]), b = m - a;
			ll tot = cycle(m), stay = M(cycle(a) * cycle(b)), change = M(tot - stay + MOD);
			ll _same = M(M(stay * same) + M(M(change * diff) * ik1));
			ll _diff = M(M(change * same) + M(M(stay + M(change * M((k - 2) * ik1))) * diff));
			same = _same, diff = _diff;
		}
		return M(k * same);
	}
};
