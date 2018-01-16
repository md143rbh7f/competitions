#include <cstdio>
#include <iterator>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using vi = vector<int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

constexpr int N = 200005;

using ms = multiset<int>;

int r[N];
vi g[N];
ms f[N];

void merge(ms & a, ms & b) {
	if (a.size() < b.size()) swap(a, b);
	a.insert(all(b));
}

ms & dfs(int u, int p) {
	auto & ans = f[u];
	for (auto & v : g[u]) if (v != p) merge(ans, dfs(v, u));
	auto it = ans.lower_bound(r[u]);
	if (!ans.empty() && it != ans.begin()) it = ans.erase(--it);
	ans.insert(it, r[u]);
	return ans;
}

int main() {
	int n, u, v;
	scanf("%d", &n);
	rep (i, n) scanf("%d", r + i);
	rep (i, n - 1) {
		scanf("%d%d", &u, &v);
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	printf("%d\n", n - dfs(0, -1).size());
	return 0;
}
