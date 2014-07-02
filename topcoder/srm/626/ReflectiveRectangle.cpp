#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define M(x) ((x)%MOD)

#define MOD 1000000007

ll mod_pow(ll a, ll b)
{
	if(!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

ll mod_inv(int a)
{
	return mod_pow(a, MOD - 2);
}

ll inv6 = mod_inv(6);

vll get_divisors(ll n)
{
	vll ans;
	ll x = 1;
	for(; x * x < n; x++) if(!(n % x)) ans.push_back(x), ans.push_back(n / x);
	if(x * x == n) ans.push_back(x);
	sort(all(ans));
	return ans;
}

ll g(ll n)
{
	return M(M(M(n * (n + 1)) * (2 * n + 1)) * inv6);
}

struct ReflectiveRectangle
{
int findSum(int a, int b, int c)
{
	if(c % 2) return 0;
	vll ds = get_divisors(c + 2);
	int m = ds.size();
	vll f(m);
	rep(i, m)
	{
		ll x = ds[i];
		f[i] = M(g(x) - f[i] + MOD);
		range(j, i + 1, m)
		{
			ll y = ds[j];
			if(y % x) continue;
			f[j] = M(f[j] + f[i] * M((y / x) * (y / x)));
		}
	}
	return M(M((ll) a * a + (ll) b * b) * f[m - 1]);
}
};
