#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define M(x) ((x)%MOD)

int MOD, mods[] = {2, 5}, * inv, invs[2][5] = {{0, 1}, {0, 1, 3, 2, 4}};

int cnt_distinct(vi & x)
{
	return set<int>(all(x)).size();
}

#define _MOD 1234567891
ll mod_pow(ll a, int b)
{
	if(!b) return 1;
	return (mod_pow((a * a) % _MOD, b / 2) * (b % 2 ? a : 1)) % _MOD;
}

inline bool zero(int x) { return !x; }
void normalise(vi & v, int j)
{
	int x = inv[v[j]];
	range(k, j, v.size()) v[k] = M(v[k] * x);
}
void zero_out(vi & v, vi & u, int j)
{
	if(zero(u[j])) return;
	int r = M(u[j] * inv[v[j]]);
	range(k, j, v.size()) u[k] = M(u[k] - M(r * v[k]) + MOD);
}

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

struct TheMagicMatrix
{
	int find(int n, vi x, vi y, vi z)
	{
		int m = x.size();
		if(cnt_distinct(x) < n && cnt_distinct(y) < n)
			return mod_pow(10, (n - 1) * (n - 1) - m + 1);

		ll ans = 1;
		int nr = 2 * n + m, nc = n * n + 1;
		rep(mi, 2)
		{
			MOD = mods[mi], inv = invs[mi];
			vector<vi> a(nr, vi(nc + 1));
			rep(i, n) rep(j, n) a[i][i * n + j] = 1;
			rep(j, n) rep(i, n) a[n + j][i * n + j] = 1;
			rep(r, 2 * n) a[r][n * n] = 1;
			rep(k, m)
			{
				a[2 * n + k][x[k] * n + y[k]] = 1;
				a[2 * n + k][n * n + 1] = z[k];
			}
			int rank = rref(a, nc);
			bool ok = true;
			rep(r, nr)
			{
				bool all_zero = true;
				rep(c, nc) if(a[r][c]) all_zero = false;
				if(all_zero && a[r][nc]) ok = false;
			}
			ans = ok * ans * mod_pow(MOD, nc - rank) % _MOD;
		}
		return ans;
	}
};
