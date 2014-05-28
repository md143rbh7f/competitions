#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 4005

int n, e0[N], e1[N], * e, s0[N], s1[N], * s, a0;
bool in[N][N];
vi g0[N], g1[N], * g;
ll ans;

int pre(int a, int v)
{
	s[a] = 1;
	for(auto & b : g[v]) if(b != a)
		s[a] += pre(b, e[b] ^ v);
	return s[a];
}

void make(vi & h, vi * _g, int * _e, int * _s)
{
	g = _g, e = _e, s = _s;
	rep(a, n - 1)
	{
		int u = a, v = h[a];
		g[u].push_back(a), g[v].push_back(a), e[a] = u ^ v;
	}
	pre(n, 0);
}

void dfs0(int a, int v)
{
	in[a][v] = true;
	for(auto & b : g0[v]) if(b != a)
	{
		dfs0(b, e0[b] ^ v);
		rep(w, n) in[a][w] |= in[b][w];
	}
}

int dfs1(int a, int v)
{
	int tot = in[a0][v];
	for(auto & b : g1[v]) if(b != a)
		tot += dfs1(b, e1[b] ^ v);
	int best = max(
		max(tot, tot - s0[a0] - s1[a] + n),
		max(s0[a0] - tot, s1[a] - tot)
	);
	if(a != n)
		ans += (ll) best * best;
	return tot;
}

struct TreesAnalysis
{
	ll treeSimilarity(vi h0, vi h1)
	{
		n = h0.size() + 1;
		make(h0, g0, e0, s0), make(h1, g1, e1, s1);
		dfs0(n, 0);
		for(; a0 < n - 1; a0++) dfs1(n, 0);
		return ans;
	}
};
