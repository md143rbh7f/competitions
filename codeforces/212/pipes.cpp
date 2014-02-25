#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)

#define N 55
#define INF 123456789

struct Edge
{
	int j, ca, co, f;
	Edge * r;
};

int n, k;
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
		if(dist[t]) f = min(f, (k - mc) / dist[t]);
		if(!f) return;
		mf += f, mc += f * dist[t];
	}
}

int main()
{
	cin >> n >> k;
	rep(i, n) rep(j, n)
	{
		int ca;
		cin >> ca;
		if(ca) add_edge(i, j, ca, 0), add_edge(i, j, k, 1);
	}
	int mc, mf;
	min_cost_max_flow(0, n - 1, mc, mf);
	cout << mf << endl;
	return 0;
}
