#include <stdio.h>

#define REP(i,a,b) for(i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int n, m, i, j, k, l, x, y, c, dp[512][26][26], prev[512][26][26][2];
char flag[512][512], edit[512][512];

int main()
{
	scanf( "%d%d", &n, &m );
	rep(i,n)
	{
		scanf( "%s", flag[i] );
		rep(j,m) flag[i][j] -= 'a';
	}
	rep(i,n)
	rep(j,26) rep(k,26)
	if( j!=k )
	{
		rep(l,m) if( flag[i][l] != ( l%2 ? k : j ) ) dp[i][j][k]++;
		if(i)
		{
			c = 1<<20;
			rep(x,26) if( x!=j )
			rep(y,26) if( y!=k )
			if( x!=y && dp[i-1][x][y]<c )
			{
				c = dp[i-1][x][y];
				prev[i][j][k][0] = x, prev[i][j][k][1] = y;
			}
			dp[i][j][k] += c;
		}
	}
	c = 1<<20;
	rep(j,26) rep(k,26) if(j!=k)
	if(dp[n-1][j][k]<c)
	{
		x = j, y = k;
		c = dp[n-1][j][k];
	}
	printf( "%d\n", c );
	for( i = n-1; i >= 0; i-- )
	{
		j = x, k = y;
		rep(l,m) edit[i][l] = ( l%2 ? k : j ) + 'a';
		x = prev[i][j][k][0], y = prev[i][j][k][1];
	}
	rep(i,n) printf( "%s\n", edit[i] );
	return 0;
}
