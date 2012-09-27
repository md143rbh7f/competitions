#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#define N 55

int xb[N], yb[N];

struct BallBouncing
{
	int bounces( int n, int m, int x0, int y0, vector<string> holes )
	{
		int k = holes.size();
		for( int i = 0; i < k; i++ ) sscanf( holes[i].c_str(), "%d%d", &xb[i], &yb[i] );

		int x = x0, y = y0;
		while( x < n && y < m )
		{
			for( int i = 0; i < k; i++ ) if( xb[i] == x && yb[i] == y ) return 0;
			x++, y++;
		}

		int dx = 1, dy = 1, cnt = 1;
		if( x == n ) x--, dx = -1;
		if( y == m ) y--, dy = -1;

		for( int t = 0; t < 1<<23; t++ )
		{
			if( dx == dy )
			{ for( int i = 0; i < k; i++ ) if( xb[i] - yb[i] == x - y ) return cnt; }
			else 
			{ for( int i = 0; i < k; i++ ) if( xb[i] + yb[i] == x + y ) return cnt; }
			int lx = dx == 1 ? n - x : x + 1, ly = dy == 1 ? m - y : y + 1;
			int l = min( lx, ly );
			x += dx * l, y += dy * l;
			if( lx == l ) x -= dx, dx = -dx;
			if( ly == l ) y -= dy, dy = -dy;
			cnt++;
		}

		return -1;
	}
};
