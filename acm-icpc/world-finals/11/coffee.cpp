#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_XY 1024
#define MAX_UV 2048

int C, X, Y, N, Q, cnt[MAX_UV][MAX_UV];
bool shop[MAX_UV][MAX_UV];

int main()
{
	for( C = 1; ; C++ )
	{
		scanf( "%d%d%d%d", &X, &Y, &N, &Q );
		if( !X && !Y && !N && !Q ) break;
		for( int u = 1; u < MAX_UV; u++ ) for( int v = 1; v < MAX_UV; v++ ) shop[u][v] = false;
		while(N--)
		{
			int x, y;
			scanf( "%d%d", &x, &y );
			shop[x+y][x-y+MAX_XY] = true;
		}
		for( int u = 1; u < MAX_UV; u++ ) for( int v = 1; v < MAX_UV; v++ )
			cnt[u][v] = shop[u][v] + cnt[u-1][v] + cnt[u][v-1] - cnt[u-1][v-1];
		printf( "Case %d:\n", C );
		while(Q--)
		{
			int d;
			scanf( "%d", &d );
			int best = 0, bestx = 1, besty = 1;
			for( int y = 1; y <= Y; y++ ) for( int x = 1; x <= X; x++ )
			{
				int u = x + y, v = x - y + MAX_XY;
				int u0 = max( u - d - 1, 0 ), v0 = max( v - d - 1, 0 );
				int u1 = min( u + d, MAX_UV - 1 ), v1 = min( v + d, MAX_UV - 1 );
				int can_reach = cnt[u1][v1] - cnt[u0][v1] - cnt[u1][v0] + cnt[u0][v0];
				if( can_reach > best )
				{
					best = can_reach;
					bestx = x;
					besty = y;
				}
			}
			printf( "%d (%d,%d)\n", best, bestx, besty );
		}
	}
	return 0;
}
