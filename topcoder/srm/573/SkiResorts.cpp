#include <algorithm>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define INF 1ll<<42
#define N 55

ll d[N][N];

struct SkiResorts
{
	ll minCost(vs g, vi h)
	{
		int n = g.size();
		set<pair<ll, pii>> q;
		rep(j, n) q.insert({d[0][j] = abs(h[0] - h[j]), {0, j}});
		range(i, 1, n) rep(j, n) d[i][j] = INF;
		while(!q.empty())
		{
			auto p = q.begin();
			int i = p->second.first, j = p->second.second;
			q.erase(p);
			rep(k, n) if(g[i][k] == 'Y')
			rep(l, n) if(h[l] <= h[j])
			{
				ll d1 = d[i][j] + abs(h[k] - h[l]);
				if(d1 < d[k][l])
				{
					q.erase({d[k][l], {k , l}});
					q.insert({d[k][l] = d1, {k , l}});
				}
			}
		}
		ll ans = INF;
		rep(j, n) ans = min(ans, d[n - 1][j]);
		return ans == INF ? -1 : ans;
	}
};
