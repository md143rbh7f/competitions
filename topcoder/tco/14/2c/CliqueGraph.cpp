#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)

#define N 5005

vi g[N];
int d[N], q[N];

struct CliqueGraph
{
ll calcSum(int n, vi V, vi S)
{
	int m = S.size(), k = n + m, s = 0;
	rep(j, S.size())
	{
		range(i, s, s + S[j])
		{
			g[V[i]].push_back(n + j);
			g[n + j].push_back(V[i]);
		}
		s += S[j];
	}
	ll ans = 0;
	rep(t, n)
	{
		clr1(d);
		d[t] = 0, q[0] = t;
		int nq = 0;
		rep(i, k)
		{
			int v = q[i];
			if(v < n) ans += d[v];
			for(auto u : g[v]) if(d[u] == -1)
			{
				d[u] = d[v] + 1;
				q[++nq] = u;
			}
		}
	}
	return ans / 4;
}
};
