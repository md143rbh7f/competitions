#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)

#define N 55
#define D 505

vi g[N];
int m, d[N][N], mem[N][N][D];

int f(int u, int v, int r)
{
	if(r < 0) return 1 + f(u, v, m);
	int & ans = mem[u][v][r];
	if(ans != -1) return ans;
	if(g[v] == vi{u}) return ans = 0;
	ans = r < m ? f(u, v, r - 1) : N;
	rep(d0, min(r, m) + 1)
	{
		int d1 = min(m - d0, d0), tot = 0;
		for(auto w : g[v]) if(w != u)
			tot += f(v, w, d1 - d[v][w]);
		for(auto w : g[v]) if(w != u)
			ans = min(ans, tot + f(v, w, d0 - d[v][w]) - f(v, w, d1 - d[v][w]));
	}
	return ans;
}

struct Ethernet
{
	int connect(vi parent, vi dist, int _m)
	{
		int n = parent.size() + 1;
		rep(i, n) rep(j, n) if(i != j) d[i][j] = D;
		rep(i, n - 1)
		{
			int u = i + 1, v = parent[i];
			g[u].push_back(v), g[v].push_back(u);
			d[u][v] = d[v][u] = dist[i];
		}
		m = _m, clr1(mem);
		int ans = N;
		rep(i, n) ans = min(ans, 1 + f(n, i, m));
		return ans;
	}
};
