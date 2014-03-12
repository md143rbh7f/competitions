#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)

#define N 105
#define INF 123456

int n;

struct Edge
{
	int j, ca, co, f;
	Edge * r;
};

vector<Edge*> g[N];

void add_edge(int i, int j, int ca, int co)
{
	Edge * e = new Edge{j, ca, co, 0, 0}, * f = new Edge{i, 0, -co, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

void min_cost_max_flow(int s, int t, int & mc, int & mf)
{
	mc = mf = 0;
	int dist[n];
	Edge * pre[n];
	while(true)
	{
		rep(i, n) dist[i] = INF;
		dist[s] = 0;
		clr(pre);
		rep(q, n)
		{
			bool change = false;
			rep(i, n) for(auto & e : g[i])
			if(e->f < e->ca && dist[i] + e->co < dist[e->j])
			{
				dist[e->j] = dist[i] + e->co, pre[e->j] = e;
				change = true;
			}
			if(!change) break;
		}
		if(!pre[t]) break;
		int f = INF;
		for(Edge * e = pre[t]; e; e = pre[e->r->j])
			f = min(f, e->ca - e->f);
		for(Edge * e = pre[t]; e; e = pre[e->r->j])
			e->f += f, e->r->f -= f;
		mf += f, mc += f * dist[t];
	}
}

int compress(vi & xs)
{
	map<int,int> id;
	for(auto & x : xs)
	{
		if(!id.count(x)) id[x] = id.size() - 1;
		x = id[x];
	}
	return id.size();
}

struct SpecialCells
{
	int guess(vi xs, vi ys)
	{
		int m = compress(xs), k = compress(ys);
		n = m + k + 2;

		vi a(m), b(k);
		for(auto & x : xs) a[x]++;
		for(auto & y : ys) b[y]++;

		set<pair<int,int>> ps;
		rep(i, xs.size()) ps.insert({xs[i], ys[i]});

		rep(i, m) add_edge(n - 2, i, a[i], 0);
		rep(j, k) add_edge(j + m, n - 1, b[j], 0);
		rep(i, m) rep(j, k) add_edge(i, j + m, 1, ps.count({i, j}));

		int mc, mf;
		min_cost_max_flow(n - 2, n - 1, mc, mf);
		return mc;
	}
};
