#include <list>
#include <string>
#include <vector>

using namespace std;

#define N 3333

int d[N][N], dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };

struct NonXorLife
{
	int countAliveCells( vector<string> g, int k )
	{
		for( int i = 0; i < N; i++ )
		for( int j = 0; j < N; j++ )
			d[i][j] = -1;

		list<int> q;
		for( int i = 0; i < g.size(); i++ )
		for( int j = 0; j < g[0].size(); j++ )
		if( g[i][j] == 'o' )
		{
			int x = i + N / 2, y = j + N / 2;
			d[x][y] = 0;
			q.push_back( x ), q.push_back( y );
		}

		int ans = 0;
		while( !q.empty() )
		{
			int x = q.front(); q.pop_front();
			int y = q.front(); q.pop_front();
			if( d[x][y] <= k ) ans++;
			else break;
			for( int i = 0; i < 4; i++ )
			{
				int xx = x + dx[i], yy = y + dy[i];
				if( d[xx][yy] > -1 ) continue;
				d[xx][yy] = 1 + d[x][y];
				q.push_back( xx ), q.push_back( yy );
			}
		}

		return ans;
	}
};
