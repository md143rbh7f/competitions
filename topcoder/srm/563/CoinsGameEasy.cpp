#include <cstring>
#include <list>
#include <string>
#include <vector>

using namespace std;

#define N 401
#define D 4

int dist[N][N], dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 }, go[N][D];

struct CoinsGameEasy
{
	int minimalSteps( vector<string> g )
	{
		int n = g.size(), m = g[0].size();

		int s0 = -1, s1 = -1;
		for( int x = 0; x < n; x++ ) for( int y = 0; y < m; y++ )
		{
			int s = x * m + y;
			if( g[x][y] == 'o' ) ( s0 == -1 ? s0 : s1 ) = s;
			for( int d = 0; d < D; d++ )
			{
				int xx = x + dx[d], yy = y + dy[d];
				if( xx < 0 || xx >= n || yy < 0 || yy >= m ) go[s][d] = -1;
				else if( g[xx][yy] == '#' ) go[s][d] = s;
				else go[s][d] = xx * m + yy;
			}
		}

		list<int> q0, q1;
		q0.push_back( s0 ), q1.push_back( s1 );
		memset( dist, -1, sizeof(dist) );
		dist[s0][s1] = 0;

		while( !q0.empty() )
		{
			s0 = q0.front(), s1 = q1.front();
			int d2 = dist[s0][s1] + 1;
			if( d2 > 10 ) break;
			q0.pop_front(), q1.pop_front();
			for( int d = 0; d < D; d++ )
			{
				int t0 = go[s0][d], t1 = go[s1][d];
				if( ( t0 == -1 ) ^ ( t1 == -1 ) ) return d2;
				if( t0 == -1 || dist[t0][t1] != -1 ) continue;
				dist[t0][t1] = d2;
				q0.push_back( t0 ), q1.push_back( t1 );
			}
		}

		return -1;
	}
};
