#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005

bool seen[N], x[N];
vi g[N], ans;

inline void add(int u)
{
	ans.push_back(u + 1), x[u] ^= 1;
}

void dfs(int u, int p)
{
	seen[u] = true;
	add(u);
	for(auto v : g[u]) if(v != p && !seen[v])
		dfs(v, u), add(u);
	if(x[u])
	{
		if(p != -1) add(p), add(u);
		else x[u] = 0, ans.pop_back();
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	rep(i, n) scanf("%d", x + i);
	rep(i, n) if(x[i])
	{
		dfs(i, -1);
		break;
	}
	rep(i, n) if(x[i])
	{
		printf("-1");
		return 0;
	}
	printf("%d\n", ans.size());
	for(auto u : ans) printf("%d ", u);
	return 0;
}
