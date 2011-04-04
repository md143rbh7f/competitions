#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

struct TeamBuilder
{
	vector<int> specialLocations( vector<string> g )
	{
		int n = g.size();
		rep(i,n) rep(j,n) g[i][j] = g[i][j]=='1';
		rep(k,n) rep(i,n) rep(j,n) g[i][j] |= g[i][k] && g[k][j];
		vector<int> ans(2);
		rep(i,n)
		{
			bool ok0 = true, ok1 = true;
			rep(j,n) if(j!=i) ok0 &= g[i][j], ok1 &= g[j][i];
			if(ok0) ans[0]++;
			if(ok1) ans[1]++;
		}
		return ans;
	}
};
