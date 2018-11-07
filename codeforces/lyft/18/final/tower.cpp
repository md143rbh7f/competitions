#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

using vi = vector<int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

constexpr int INF = 1000000000;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	vi vs;
	rep (i, n) {
		int x;
		scanf("%d", &x);
		vs.push_back(x);
	}
	sort(all(vs));
	vs.push_back(INF);

	vi hs;
	rep (i, m) {
		int x0, x1, y;
		scanf("%d%d%d", &x0, &x1, &y);
		if (x0 == 1) hs.push_back(x1);
	}
	sort(all(hs));

	int ans = INF;
	rep (i, n + 1)
		ans = min(ans, i + (int) (hs.end() - lower_bound(all(hs), vs[i])));
	printf("%d\n", ans);

	return 0;
}
