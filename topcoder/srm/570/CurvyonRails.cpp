#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)

#define H 29
#define N 2*H*H
#define INF 1234567

int n, id[H][H], del[2][2] = {{-1, 1}, {0, 0}};

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

struct CurvyonRails
{
	int getmin(vs field)
	{
		int h = field.size(), w = field[0].size(), m = 0;
		CLR(id, -1);
		rep(i, h) rep(j, w) if(field[i][j] != 'w') id[i][j] = m++;
		n = 2 * m + 2;
		rep(i, h) rep(j, w) if(id[i][j] != -1) rep(o, 2)
		{
			int v = 2 * id[i][j] + o;
			add_edge(v, v ^ 1, 1, field[i][j] == 'C');
			if((i + j) % 2) add_edge(v, n - 1, 1, 0);
			else
			{
				add_edge(n - 2, v, 1, 0);
				rep(d, 2)
				{
					int x = i + del[o][d], y = j + del[!o][d];
					if(x < 0 || x >= h || y < 0 || y >= w || id[x][y] == -1)
						continue;
					add_edge(v, 2 * id[x][y] + o, 1, 0);
				}
			}
		}
		int mc, mf;
		min_cost_max_flow(n - 2, n - 1, mc, mf);
		return mf < m ? -1 : mc;
	}
};
