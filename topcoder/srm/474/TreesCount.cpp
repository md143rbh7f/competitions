#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int d[50], p[50];
set< pair<int,int> > q;

struct TreesCount
{
	int count( vector<string> g )
	{
		int n = g.size();
		REP(i,1,n) d[i] = 111111111;
		rep(i,n) rep(j,n) g[i][j] -= '0';
		q.insert(make_pair(0,0));
		while(!q.empty())
		{
			int x = q.begin()->second;
			q.erase(q.begin());
			rep(y,n) if( g[x][y] && d[x] + g[x][y] < d[y] )
			{
				q.erase(make_pair(d[y],y));
				d[y] = d[x] + g[x][y];
				q.insert(make_pair(d[y],y));
			}
		}
		rep(i,n) rep(j,n) if( g[i][j] && d[i] + g[i][j] == d[j] ) p[j]++;
		long long ans = 1;
		REP(i,1,n) ans = (ans*p[i])%1000000007;
		return (int)ans;
	}
};
