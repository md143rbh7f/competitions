#include <stdio.h>

#define rep(i,n) for(i=0;i<(n);i++)
#define MAX 101

int d, e, g[MAX][MAX], h, i, j, k, l, m, n, list[MAX][MAX][MAX], len[MAX][MAX], dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 }, ok, x, y, seen[MAX];
char words[MAX][MAX], grid[MAX][MAX];

void dfs( int v )
{
	if(seen[v]) return;
	seen[v] = 1;
	int u;
	rep(u,l) if(g[v][u]) dfs(u);
}

int main()
{
	while(1)
	{
		scanf( "%d%d%d", &n, &m, &l );
		if((!n)&&(!m)&&(!l)) break;
		rep(i,n) scanf( "%s", grid[i] );
		rep(i,l)
		{
			scanf( "%s", words[i] );
			for( j = 0; words[i][j]; j++ ) if( words[i][j]>='a' && words[i][j]<='z' ) words[i][j] += 'A'-'a';
		}
		rep(i,MAX) rep(j,MAX) len[i][j] = g[i][j] = 0;
		rep(i,n) rep(j,m) rep(k,l) rep(d,8)
		{
			ok = 1;
			for( h = 0; words[k][h]; h++ )
			{
				x = i + h*dx[d], y = j + h*dy[d];
				if( x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != words[k][h] )
				{
					ok = 0;
					break;
				}
			}
			if(ok) for( h = 0; words[k][h]; h++ )
			{
				x = i + h*dx[d], y = j + h*dy[d];
				rep(e,len[x][y]) g[k][list[x][y][e]] = g[list[x][y][e]][k] = 1;
				list[x][y][len[x][y]++] = k;
			}
		}
		rep(i,l) seen[i] = 0;
		dfs(0);
		ok = 1;
		rep(i,l) if(!seen[i]) ok = 0;
		rep(i,l)
		{
			k = 0;
			rep(j,l) if(g[i][j]) k++;
			if( l>2 && k<2 ) ok = 0;
		}
		printf( ok ? "Yes\n" : "No\n" );
	}
	return 0;
}
