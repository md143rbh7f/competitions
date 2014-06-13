#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define M(x) ((x)%MOD)

const int N = 2014, INF = 234567890, MOD = 1000000009;

int d0[N], d1[N], w[N];
struct edge { int v, d; };
vector<edge> g[N];
struct by
{
	int * x;
	inline bool operator()(int a, int b) const
	{ return x[a] < x[b] || (x[a] == x[b] && a < b); }
};

void dijkstra(int n, int s, int * d)
{
	rep(i, n) d[i] = INF;
	d[s] = 0, w[s] = 1;
	set<int, by> q({s}, by{d});
	while(!q.empty())
	{
		int u = *q.begin();
		q.erase(u);
		for(auto & e : g[u])
		{
			if(d[e.v] > d[u] + e.d)
			{
				q.erase(e.v);
				d[e.v] = d[u] + e.d, w[e.v] = 0;
				q.insert(e.v);
			}
			if(d[e.v] == d[u] + e.d)
				w[e.v] = M(w[e.v] + w[u]);
		}
	}
}

struct DrivingPlans
{
int count(int n, vi a, vi b, vi c)
{
	rep(j, a.size())
	{
		g[a[j] - 1].push_back({b[j] - 1, c[j]});
		g[b[j] - 1].push_back({a[j] - 1, c[j]});
	}
	dijkstra(n, 0, d0), dijkstra(n, n - 1, d1);
	rep(u, n) if(d0[u] + d1[u] == d0[n - 1])
	for(auto & e : g[u]) if(!e.d)
		return -1;
	return w[0];
}
};
