#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 305
#define MOD 1000000009

int n, x[N], a, b, ways[N][N][3];

inline bool ok(int i, int j)
{
	return a <= x[j] - x[i] && x[j] - x[i] <= b;
}

struct TheExperiment
{
	int countPlacements(vs _x, int m, int l, int _a, int _b)
	{
		a = _a, b = _b;
		for(auto & s : _x) for(auto c : s)
			x[n + 1] = x[n] + c - '0', n++;

		ways[0][0][0] = 1;
		rep(t, m) rep(i, n)
		{
			range(j, 1, min(l, n - i) + 1) if(ok(i, i + j)) rep(k, 3)
				(ways[t + 1][i + j][j == l ? 2 : max(k, 1)] += ways[t][i][k]) %= MOD;
			(ways[t][i + 1][0] += (ways[t][i][0] + ways[t][i][2]) % MOD) %= MOD;
		}

		int ans = 0;
		rep(i, n + 1) (ans += ways[m][i][2]) %= MOD;
		return ans;
	}
};
