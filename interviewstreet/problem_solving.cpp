#include <algorithm>
#include <cstdio>

using namespace std;

#define M 305
#define N 605
#define INF 9001

int t, m, n, k, v[M], g[N][N], f[N][N];
bool seen[N];

int dfs( int s, int t, int minf )
{
	if( s == t ) return minf;
	if( seen[s] ) return 0;
	seen[s] = true;
	for( int i = 0; i < n; i++ )
	{
		if( g[s][i] == f[s][i] ) continue;
		int minf2 = min( minf, g[s][i] - f[s][i] );
		minf2 = min( minf2, dfs( i, t, minf2 ) );
		if( minf2 )
		{
			f[s][i] += minf2;
			f[i][s] -= minf2;
			return minf2;
		}
	}
	return 0;
}

int max_flow( int s, int t )
{
	for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) f[i][j] = 0;
	do for( int i = 0; i < n; i++ ) seen[i] = false;
	while( dfs( s, t, INF ) );
	int ans = 0;
	for( int i = 0; i < n; i++ ) ans += f[s][i];
	return ans;
}

int main()
{
	scanf( "%d\n", &t );
	while(t--)
	{
		scanf( "%d%d", &m, &k );
		n = 2 * m + 2;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) g[i][j] = 0;
		for( int i = 0; i < m; i++ )
		{
			scanf( "%d", &v[i] );
			g[n-2][i] = g[i+m][n-1] = 1;
			for( int j = 0; j < i; j++ ) g[j][i+m] = v[i] - v[j] >= k || v[j] - v[i] >= k;
		}
		printf( "%d\n", m - max_flow( n-2, n-1 ) );
	}
	return 0;
}
