#include <bitset>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 55

inline bool zero(bool x) { return !x; }
template <size_t SZ>
void normalise(bitset<SZ> & v, int j) {}
template <size_t SZ>
void zero_out(bitset<SZ> & v, bitset<SZ> & u, int j) { if(u[j]) u ^= v; }

template <typename T>
int rref(vector<T> & a, int m = 0)
{
	int n = a.size(), r = 0;
	if(!m) m = a[0].size();
	rep(j, m)
	{
		bool found = false;
		range(i, r, n) if(!zero(a[i][j]))
		{
			found = true;
			swap(a[r], a[i]);
			break;
		}
		if(!found) continue;
		normalise(a[r], j);
		rep(i, n) if(!zero(a[i][j]) && i != r) zero_out(a[r], a[i], j);
		r++;
	}
	return r;
}

struct XorCards
{
	ll numberOfWays(vll xs, ll lim)
	{
		for(auto & x : xs) x *= 2;
		lim = 2 * lim + 1;
		int n = xs.size();
		xs.push_back(lim);
		ll ans = 0;
		rep(b, N) if(lim & (1ll << b))
		{
			vector<bitset<N>> a(N - b);
			rep(j, N - b) rep(i, n + 1) a[j][i] = (xs[i] >> (b + j)) & 1;
			a[0][n] = 0;
			int rank = rref(a, n);
			bool ok = true;
			rep(j, N - b) if(a[j].to_ulong() == 1ll << n) ok = false;
			if(ok) ans += 1ll << (n - rank);
		}
		return ans;
	}
};
