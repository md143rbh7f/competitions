#include <algorithm>
#include <cstdio>
#include <cstring>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)
#define tup make_tuple

#define N 300005

vi g[N];
int dia[N];

template <int S>
struct UnionFind
{
int par[S];

void clear() { clr1(par); }
UnionFind() { clear(); }

int find(int x)
{
	int y = x;
	while(par[y] >= 0) y = par[y];
	while(par[x] >= 0) tie(x, par[x]) = tup(par[x], y);
	return y;
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	if(x == y) return;
	if(par[x] > par[y]) swap(x, y);
	par[x] += par[y], par[y] = x;
	dia[x] = max(max(dia[x], dia[y]), (dia[x] + 1) / 2 + (dia[y] + 1) / 2 + 1);
}
};

UnionFind<N> uf;

int rec(int v, int u, int i)
{
	if(v != i) uf.par[v] = i, uf.par[i]--;
	int r = 0;
	for(auto w : g[v]) if(w != u)
	{
		int q = rec(w, v, i);
		dia[v] = max(dia[v], max(dia[w], r + q + 1));
		r = max(r, q + 1);
	}
	return r;
}

int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	
	while(m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].push_back(b), g[b].push_back(a);
	}

	rep(i, n) if(uf.find(i) == i) rec(i, -1, i);

	while(q--)
	{
		int t, x;
		scanf("%d%d", &t, &x);
		if(t == 1) printf("%d\n", dia[uf.find(x - 1)]);
		else
		{
			int y;
			scanf("%d", &y);
			uf.merge(x - 1, y - 1);
		}
	}

	return 0;
}
