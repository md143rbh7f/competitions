#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

#define INF 123456789
#define N 1000

struct Edge
{
	int j, c, f;
	Edge * r;
};

vector<Edge*> g[N];
int n;

void add_edge(int i, int j, int c = 1)
{
	Edge* e = new Edge{j, c, 0, 0}, *f = new Edge{i, 0, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

bool seen[N];

int dfs(int s, int t, int mf)
{
	if(s == t) return mf;
	if(seen[s]) return 0;
	seen[s] = true;
	for(auto e : g[s]) if(e->c > e->f)
	{
		int mf2 = min(mf, e->c - e->f);
		mf2 = min(mf2, dfs(e->j, t, mf2));
		if(mf2)
		{
			e->f += mf2, e->r->f -= mf2;
			return mf2;
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	for(clr0(seen); dfs(s, t, INF); clr0(seen));
	int ans = 0;
	for(auto e : g[s]) ans += e->f;
	return ans;
}

#define K 105
#define Q (1<<15)
#define R 3600

int nv, ne, xs[K], ys[K], u[K], v[K], ps[R], np;
bool isp[Q];

void generate_primes()
{
	range(p, 2, Q) isp[p] = true;
	range(p, 2, Q) if(isp[p])
	{
		ps[np++] = p;
		for(int q = p * p; q < Q; q += p) isp[q] = false;
	}
}

void process(int p)
{
	rep(i, nv)
	{
		int e;
		for(e = 0; !(xs[i] % p); e++) xs[i] /= p;
		if(e)
		{
			ys[i] = n++;
			if(i % 2) add_edge(ys[i], 1, e);
			else add_edge(0, ys[i], e);
		}
		else ys[i] = -1;
	}

	rep(j, ne) if(ys[u[j]] != -1 && ys[v[j]] != -1)
		add_edge(ys[u[j]], ys[v[j]], INF);
}

int main()
{
	generate_primes();

	cin >> nv >> ne;
	rep(i, nv) cin >> xs[i];
	rep(j, ne)
	{
		cin >> u[j] >> v[j];
		u[j]--, v[j]--;
		if(u[j] % 2) swap(u[j], v[j]);
	}

	n = 2;
	range(p, ps, ps + np) process(*p);
	range(x, xs, xs + nv) if(*x != 1) process(*x);

	cout << max_flow(0, 1) << endl;

	return 0;
}
