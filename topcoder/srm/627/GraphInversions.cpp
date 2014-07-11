#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define INF 1234567890
#define N 1005

vi y, g[N];
bool seen[N];

int tree[N+1];

void add(int x, int amt)
{
	for(; x <= N; x += x&(-x)) tree[x] += amt;
}

int cum_freq(int x)
{
	int ans = 0;
	for(; x; x -= x&(-x)) ans += tree[x];
	return ans;
}

int dfs(int u, int v, int k, int tot)
{
	if(k == 1) return tot;
	add(y[v], 1);
	seen[v] = true;
	int ans = INF;
	for(auto w : g[v]) if(w != u && !seen[w])
		ans = min(ans, dfs(v, w, k - 1, tot + cum_freq(y[w] - 1)));
	seen[v] = false;
	add(y[v], -1);
	return ans;
}

struct GraphInversions
{
int getMinimumInversions(vi a, vi b, vi _y, int k)
{
	y = _y;
	int n = a.size(), ans = INF;
	rep(i, n) g[a[i]].push_back(b[i]), g[b[i]].push_back(a[i]);
	rep(i, n) ans = min(ans, dfs(-1, i, k, 0));
	return ans == INF ? -1 : ans;
}
};
