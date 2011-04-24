#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 50
#define MAX2 MAX*(MAX+1)/2

int di[] = { -1, -1, 0, 1, 1, 0 }, dj[] = { -1, 0, 1, 1, 0, -1 }, n, adj[6], b[50][50];
bool seen[MAX2], g[MAX2][MAX2];

int dfs( int x )
{
	if(seen[x]) return 0;
	seen[x] = true;
	int ans = 1;
	rep(y,n) if(g[x][y]) ans += dfs(y);
	return ans;
}

struct HexagonPuzzle
{
	int theCount( vector<string> B )
	{
		int m = B.size();
		rep(i,m) rep(j,i+1) b[i][j] = B[i][j]=='.' ? n++ : -1;
		rep(i,m) rep(j,i+1) if(b[i][j]>-1)
		{
			rep(d,6)
			{
				int I = i+di[d], J = j+dj[d];
				if( I >= 0 && I < m && J >= 0 && J <= I && b[I][J] > -1 ) adj[d] = b[I][J];
				else adj[d] = -1;
			}
			int x = b[i][j];
			rep(d,6)
			{
				int y = adj[d], z = adj[(d+1)%6];
				if( y>-1 && z>-1 ) g[x][y] = g[y][x] = g[x][z] = g[z][x] = g[y][z] = g[z][y] = true;
			}
		}
		long long ans = 1;
		rep(i,n) if(!seen[i]) for( int cnt = dfs(i); cnt > 2; cnt-- ) ans = (ans*cnt)%1000000007;
		return (int)ans;
	}
};
