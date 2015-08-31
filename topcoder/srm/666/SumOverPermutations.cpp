#include <algorithm>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

#define MOD 1000000007
#define N 4004

int n;
ll mem[3][N], choose[N][N], work(int, int);

ll _work(int c, int m)
{
	if(!m) return 1;
	ll ans = 0;
	int l = min(c + 1, 2), r = max(1, c);
	rep(i, m)
	{
		int cur = n - (i == 0 && c > 0) - (i == m - 1 && c == 2);
		ans = M(ans + M(choose[m - 1][i] * M(work(l, i) * M(cur * work(r, m - 1 - i)))));
	}
	return ans;
}

ll work(int c, int m)
{
	ll & ans = mem[c][m];
	return ans ? ans : ans = _work(c, m);
}

struct SumOverPermutations
{
int findSum(int _n)
{
	rep(i, N) choose[i][0] = 1;
	range(i, 1, N) range(j, 1, i + 1)
		choose[i][j] = M(choose[i-1][j] + choose[i-1][j-1]);
	n = _n;
	return work(0, n);
}
};
