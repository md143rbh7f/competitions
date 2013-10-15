#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 55

vi a, b;
int dp[N][N];

int run(int i0, int j0)
{
	int n = a.size() - i0, m = b.size() - j0, ans = 0;
	rep(i,n) rep(j,m)
		ans = max(ans, dp[i+1][j+1] = max(
			((ll) a[i0] * b[j0+j] == (ll) a[i0+i] * b[j0]) + dp[i][j],
			max(dp[i+1][j], dp[i][j+1])
		));
	return ans;
}

struct AstronomicalRecords
{
	int minimalPlanets(vi _a, vi _b)
	{
		a = _a, b = _b;
		int n = a.size(), m = b.size(), ans = 0;
		rep(i,n) rep(j,m) ans = max(ans, run(i, j));
		return n + m - ans;
	}
};
