#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

using vi = vector<int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

constexpr int S = 905, N = 35, INF = 12345678;

int best[N][S], par[N][S];

struct DieDesign {
vi design(vi xs) {
	rep (i, N) rep (s, S) best[i][s] = INF;

	int n = xs.size();
	sort(all(xs));
	best[0][0] = 0;
	rep (i, n) rep (s, S) if (best[i][s] < INF) {
		if (best[i][s] < best[i + 1][s]) {
			best[i + 1][s] = best[i][s];
			par[i + 1][s] = s;
		}
		rep (j, n) if (best[i][s] + xs[j] + 1 < best[i + 1][s + j + 1]) {
			best[i + 1][s + j + 1] = best[i][s] + xs[j] + 1;
			par[i + 1][s + j + 1] = s;
		}
	}

	int s = S - 1, tot = accumulate(all(xs), 0);
	vi ans;
	while (best[n][s] > tot) s--;
	for (int i = n; i > 0; i--) {
		ans.push_back(best[i][s] - best[i - 1][par[i][s]]);
		s = par[i][s];
	}
	ans[0] += tot - accumulate(all(ans), 0);

	return ans;
}
};
