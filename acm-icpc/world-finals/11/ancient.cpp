#include <cstdio>
#include <set>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define N 205
#define L 55
#define NC 40005
#define T 6

char buf[L], code[] = "ADJKSW";
int h, w, nc, comp[N][N], cnt[T], id[] = { 5, 0, 3, 2, 4, 1 }, dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
bool grid[N][N], interior[NC], color[NC];
set<int> g[NC];

void dfs( int i, int j, bool c )
{
	comp[i][j] = nc;
	for( int d = 0; d < 4; d++ )
	{
		int x = i + dx[d], y = j + dy[d];
		if( x < 0 || x >= h || y < 0 || y >= w ) continue;
		bool seen = comp[x][y] > -1, same = grid[x][y] == c;
		if( !seen && same ) dfs( x, y, c );
		if( seen && !same ) g[nc].insert(comp[x][y]), g[comp[x][y]].insert(nc);
	}
}

int main()
{
	for( int t = 1; ; t++ )
	{
		scanf( "%d%d", &h, &w );
		if( !h && !w ) break;

		rep(i,h)
		{
			scanf( "%s", buf );
			rep(j,w)
			{
				if( '0' <= buf[j] && buf[j] <= '9' ) buf[j] -= '0';
				else buf[j] = buf[j] - 'a' + 10;
				rep(k,4) grid[i][4*j+k] = ( buf[j] >> ( 3 - k ) ) & 1;
			}
		}

		w *= 4;
		nc = 0;
		rep(i,h) rep(j,w) comp[i][j] = -1;
		rep(i,h) rep(j,w) if( comp[i][j] == -1 )
		{
			color[nc] = grid[i][j];
			interior[nc] = true;
			g[nc].clear();
			dfs( i, j, grid[i][j] );
			nc++;
		}
		rep(c,nc) if( g[c].size() > 1 ) interior[c] = false;
		rep(i,h) interior[comp[i][0]] = interior[comp[i][w-1]] = false;
		rep(j,w) interior[comp[0][j]] = interior[comp[h-1][j]] = false;

		rep(c,nc) if(color[c])
		{
			int holes = 0;
			foreach(it,g[c]) if(interior[*it]) holes++;
			cnt[id[holes]]++;
		}

		printf( "Case %d: ", t );
		rep(i,T) for( ; cnt[i]; cnt[i]-- ) putchar(code[i]);
		puts("");
	}
	return 0;
}
