#include <list>
#include <string>
#include <vector>

using namespace std;

#define M 55
#define N 2*M

int n, d[M][M], prev[N], g[N][N], f[N][N];

int bfs( int s, int t )
{
	list<int> q;
	prev[s] = -2;
	q.push_back(s);
	while( !q.empty() )
	{
		int i = *q.begin();
		q.pop_front();
		for( int j = 0; j < n; j++ ) if( g[i][j] > f[i][j] && prev[j] == -1 ) prev[j] = i, q.push_back( j );
	}
	if( prev[t] == -1 ) return 0;
	int ans = g[prev[t]][t] - f[prev[t]][t];
	for( int v = t; prev[v] >= 0; v = prev[v] ) ans = min( ans, g[prev[v]][v] - f[prev[v]][v] );
	for( int v = t; prev[v] >= 0; v = prev[v] ) f[prev[v]][v] += ans, f[v][prev[v]] -= ans;
	return ans;
}

int max_flow( int s, int t )
{
	for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) f[i][j] = 0;
	do for( int i = 0; i < n; i++ ) prev[i] = -1;
	while( bfs( s, t ) );
	int ans = 0;
	for( int i = 0; i < n; i++ ) ans += f[s][i];
	return ans;
}

struct Incubator
{
	int maxMagicalGirls( vector<string> h )
	{
		n = h.size();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) d[i][j] = h[i][j] == 'Y';
		for( int k = 0; k < n; k++ ) for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
			d[i][j] |= d[i][k] & d[k][j];
		int s = 2 * n, t = 2 * n + 1, m = 0;
		for( int i = 0; i < n; i++ ) if( !d[i][i] )
		{
			m++, g[s][i] = g[i+n][t] = 1;
			for( int j = 0; j < n; j++ ) if( !d[j][j] && d[i][j] ) g[i][j+n] = 1;
		}
		n = 2 * n + 2;
		return m - max_flow( n - 2, n - 1 );
	}
};
