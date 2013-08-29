#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define INF 123456789
#define N 5005
#define M 30005

#define in(i,j) 2 * ( i * y + j )
#define out(i,j) 2 * ( i * y + j ) + 1

char dc[] = { 'D', 'R', 'U', 'L' };
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int n, m, a[M], b[M], cap[M], cost[M], flow[M], dist[N], prev[N];

inline void add_edge( int u, int v, int _cap, int _cost )
{
	a[m] = u, b[m] = v, cap[m] = _cap, cost[m] = _cost, m++;
	a[m] = v, b[m] = u, cap[m] = 0, cost[m] = -_cost, m++;
}

void min_cost_max_flow( int s, int t, int & mc, int & mf )
{
	mc = mf = 0;
	for( int i = 0; i < m; i++ ) flow[i] = 0;
	while(1)
	{
		for( int i = 0; i < n; i++ ) dist[i] = INF, prev[i] = -1;
		dist[s] = 0;
		for( int i = 0; i < n; i++ )
		{
			bool change = false;
			for( int j = 0; j < m; j++ )
			if( flow[j] < cap[j] && dist[a[j]] + cost[j] < dist[b[j]] )
			{
				dist[b[j]] = dist[a[j]] + cost[j];
				prev[b[j]] = j;
				change = true;
			}
			if( !change ) break;
		}

		if( prev[t] != -1 )
		{
			int f = INF;
			for( int j = prev[t]; j != -1; j = prev[a[j]] ) f = min( f, cap[j] - flow[j] );
			for( int j = prev[t]; j != -1; j = prev[a[j]] ) flow[j] += f, flow[j^1] -= f;
			mf += f, mc += f * dist[t];
		}
		else break;
	}
}

struct DirectionBoard
{
	int getMinimum( vector<string> g )
	{
		int x = g.size(), y = g[0].size(), mc, mf;
		n = 2 * x * y + 2;
		for( int i = 0; i < x; i++ ) for( int j = 0; j < y; j++ ) 
		{
			for( int d = 0; d < 4; d++ )
			{
				int ii = ( i + dx[d] + x ) % x, jj = ( j + dy[d] + y ) % y;
				add_edge( in( i, j ), out( ii, jj ), 1, g[i][j] != dc[d] );
			}
			add_edge( n - 2, in( i, j ), 1, 0 );
			add_edge( out( i, j ), n - 1, 1, 0 );
		}
		min_cost_max_flow( n - 2, n - 1, mc, mf );
		return mc;
	}
};
