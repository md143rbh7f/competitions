#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

map< int, vi > g;
map< int, map< int, vi > > d;
int n, m, p, q;
bool seen[100];
ll ans;

void dfs( int x )
{
	if(seen[x]) return;
	seen[x] = true;
	if(x<n) p++;
	else q++;
	rep(y,g[x].size()) dfs(g[x][y]);
}

struct OneDimensionalBalls
{
	ll countValidGuesses( vi a, vi b )
	{
		n = a.size(), m = b.size();
		rep(i,n) rep(j,m)
		{
			int dist = abs(a[i]-b[j]);
			if(dist)
			{
				d[dist][i].push_back(n+j);
				d[dist][n+j].push_back(i);
			}
		}
		foreach(it,d)
		{
			ll cnt = 1;
			g = it->second;
			rep(i,n+m) seen[i] = false;
			rep(i,n) if(!seen[i])
			{
				p = q = 0;
				dfs(i);
				if(p>q) cnt = 0;
				if(p<q) cnt *= q;
			}
			ans += cnt;
		}
		return ans;
	}
};
