#include <vector>

using namespace std;

#define N 55

int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool seen[2*N][2*N];

struct RotatingBot
{
	int minArea( vector<int> moves )
	{
		int x = N, y = N, dir = 0, x0 = N, y0 = N, x1 = N, y1 = N;
		
		for( int i = 0; i < moves.size(); i++ )
		{
			x += moves[i] * dx[dir], y += moves[i] * dy[dir];
			if( x < x0 ) x0 = x;
			if( y < y0 ) y0 = y;
			if( x > x1 ) x1 = x;
			if( y > y1 ) y1 = y;
			dir = (dir+1)%4;
		}

		x = N, y = N, dir = 0;
		seen[x][y] = true;
		for( int i = 0; i < moves.size(); i++ )
		{
			for( int j = 0; j < moves[i]; j++ )
			{
				x += dx[dir], y += dy[dir];
				if( seen[x][y] ) return -1;
				seen[x][y] = true;
			}
			int tx = x + dx[dir], ty = y + dy[dir];
			if( i < moves.size() - 1 && tx >= x0 && tx <= x1 && ty >= y0 && ty <= y1 && !seen[tx][ty] ) return -1;
			dir = (dir+1)%4;
		}
		
		return ( x1 - x0 + 1 ) * ( y1 - y0 + 1 );
	}
};
