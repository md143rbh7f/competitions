#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005
#define INF (1ll<<60)

struct Edge { int v, d; bool train; };

vector<Edge> g[N];
ll dist[N];
bool need[N];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	rep(e, m)
	{
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		u--, v--;
		g[u].push_back({v, x, false});
		g[v].push_back({u, x, false});
	}

	rep(e, k)
	{
		int v, x;
		scanf("%d%d", &v, &x);
		v--;
		g[0].push_back({v, x, true});
	}

	range(i, 1, n) dist[i] = INF;
	set<pair<ll, int>> q;
	q.insert({0, 0});
	while(!q.empty())
	{
		int u = q.begin()->second;
		q.erase(q.begin());
		for(auto e : g[u])
		{
			if(dist[u] + e.d < dist[e.v])
			{
				q.erase({dist[e.v], e.v});
				dist[e.v] = dist[u] + e.d;
				q.insert({dist[e.v], e.v});
				need[e.v] = e.train;
			}
			else if(dist[u] + e.d == dist[e.v] && !e.train)
				need[e.v] = false;
		}
	}

	int ans = k;
	rep(i, n) ans -= need[i];
	printf("%d", ans);

	return 0;
}
