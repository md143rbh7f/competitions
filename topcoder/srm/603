#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define M(x) ((x)%MOD)

#define MOD 1000000007
#define N (1<<12)

ll cnt[N];

ll mod_exp(ll a, ll b)
{
	if(!b) return 1;
	if(b % 2) return M(a * mod_exp(M(a * a), b / 2));
	return mod_exp(M(a * a), b / 2);
}

vll get_factors(ll n)
{
	vll ans;
	ll f = 1;
	for(; f * f < n; f++) if(!(n % f)) ans.push_back(f), ans.push_back(n / f);
	if(f * f == n) ans.push_back(f);
	sort(all(ans));
	return ans;
}

struct PairsOfStrings
{
	int getNumber(int n, int k)
	{
		vll factors = get_factors(n);
		int m = factors.size();
		ll ans = 0;
		rep(i, m)
		{
			int x = factors[i];
			cnt[i] = M(mod_exp(k, x) - cnt[i] + MOD);
			ans = M(ans + M(x * cnt[i]));
			range(j, i + 1, m)
			{
				int y = factors[j];
				if(y % x) continue;
				cnt[j] = M(cnt[j] + cnt[i]);
			}
		}
		return ans;
	}
};
