#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <utility>

using namespace std;

typedef pair< double, pair< int, int > > state;
#define N 10000
#define S 11
#define make_state( a, b, c ) ( make_pair( a, make_pair( b, c ) ) )
#define slope( v1, v2 ) ( (int) floor( 100 * ( z[v2] - z[v1] ) / hypot( x[v2] - x[v1], y[v2] - y[v1] ) ) )
#define edge_dist( v1, v2 ) ( hypot( hypot( x[v2] - x[v1], y[v2] - y[v1] ), z[v2] - z[v1] ) )

int n, m, a, b, c, x[N], y[N], z[N], INF = 1<<30;
vector<int> g[N];
double dist[N][S];
set<state> q;

int main()
{
	while(1)
	{
		scanf( "%d%d", &n, &m );
		if( !n && !m ) break;
		for( int v = 0; v < n; v++ )
		{
			scanf( "%d%d%d", &x[v], &y[v], &z[v] );
			g[v].clear();
			for( int s = 0; s < S; s++ ) dist[v][s] = INF;
		}
		for( int i = 0; i < m; i++ )
		{
			scanf( "%d%d", &a, &b );
			a--, b--;
			g[a].push_back(b), g[b].push_back(a);
		}
		scanf( "%d%d%d", &a, &b, &c );
		a--, b--;
		q.insert( make_state( 0, a, 0 ) );
		dist[a][0] = 0;
		while(!q.empty())
		{
			int v1 = q.begin()->second.first, s1 = q.begin()->second.second;
			q.erase(q.begin());
			for( int i = 0; i < g[v1].size(); i++ )
			{
				int v2 = g[v1][i];
				int s = slope( v1, v2 );
				if( s < 0 ) s = 0;
				if( s >= S ) continue;
				double d = edge_dist( v1, v2 );
				int s2 = s > s1 ? s : s1;
				if( dist[v1][s1] + d < dist[v2][s2] )
				{
					q.erase( make_state( dist[v2][s2], v2, s2 ) );
					dist[v2][s2] = dist[v1][s1] + d;
					q.insert( make_state( dist[v2][s2], v2, s2 ) );
				}
			}
			if( dist[a][0] == 0 ) dist[a][0] = INF;
		}
		if( dist[b][c] == INF ) printf( "None\n" );
		else printf( "%.3f\n", dist[b][c] );
	}
	return 0;
}
