#include <algorithm>
#include <cstring>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)
#define acc(f,x,y) x=f(x,y)

#define INF 12345678

int n, m, mem[2][2][2][2][2][2][2][2];
vs a;

int sq(bool x0, bool x1, bool x2, bool x3, bool x01, bool x23, bool x02, bool x13)
{
	int & ans = mem[x0][x1][x2][x3][x01][x23][x02][x13];
	if(ans != -1) return ans;
	if((!x01 || (x0 == x1)) && (!x23 || (x2 == x3)) && (!x02 || (x0 == x2)) && (!x13 || (x1 == x3)))
		return ans = 0;
	ans = INF;
	return ans = 1 + min(
		min(
			sq(!x0, x1, x2, x3, x01, x23, x02, x13),
			sq(x0, !x1, x2, x3, x01, x23, x02, x13)
		),
		min(
			sq(x0, x1, !x2, x3, x01, x23, x02, x13),
			sq(x0, x1, x2, !x3, x01, x23, x02, x13)
		)
	);
}

int solve(int s, int r)
{
	vi best {0};
	rep(i, n / 2)
	{
		vi e(3, INF);
		rep(u, 2) rep(v, 2)
		{
			int tot = 0;
			rep(j, m / 2) tot += sq(
				a[i][j], a[i][m - j - 1],
				a[n - i - 1][j], a[n - i - 1][m - j - 1],
				u, v,
				(s >> j) & 1, (s >> (m - j - 1)) & 1
			);
			acc(min, e[u + v], tot);
		}
		vi next(2 * i + 3, INF);
		rep(u, 2 * i + 1) rep(v, 3) acc(min, next[u + v], best[u] + e[v]);
		best = move(next);
	}
	return best[r];
}

struct PalindromeMatrix
{
	int minChange(vs _a, int r, int c)
	{
		clr1(mem);
		a = move(_a), n = a.size(), m = a[0].size();
		rep(i, n) rep(j, m) a[i][j] -= '0';
		int ans = INF;
		rep(s, 1<<m) if(__builtin_popcount(s) == c) acc(min, ans, solve(s, r));
		return ans;
	}
};
