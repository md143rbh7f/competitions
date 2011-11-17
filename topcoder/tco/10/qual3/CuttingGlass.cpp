#include <queue>
#include <string>
#include <vector>

using namespace std;

int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 }, n, m; // L, R, U, D
bool cut[1010][1010][5], seen[1010][1010];
queue<int> qx, qy;

void bfs( int x, int y )
{
	qx.push(x), qy.push(y);
	while( !qx.empty() )
	{
		x = qx.front(), qx.pop(), y = qy.front(), qy.pop();
		if( x<0 || y<0 || x>=n || y>=m || seen[x][y] ) continue;
		seen[x][y] = true;
		for( int d = 0; d < 4; d++ ) if( !cut[x][y][d] ) qx.push( x+dx[d] ), qy.push( y+dy[d] );
	}
}

class CuttingGlass
{
	public:
	int pieces( int w, int h, int x, int y, vector<string> program )
	{
		n = w, m = h;
		for( int i = 0; i < program.size(); i++ ) for( int j = 0; j < program[i].size(); j++ )
		{
			int x1 = 0, y1 = 0, x2 = 0, y2 = 0, d = 0;
			switch( program[i][j] )
			{
				case 'L':
					x1 = x-1, y1 = y-1, x2 = x-1, y2 = y;
					x--;
					d = 3;
					break;
				case 'R':
					x1 = x, y1 = y-1, x2 = x, y2 = y;
					x++;
					d = 3;
					break;
				case 'U':
					x1 = x-1, y1 = y-1, x2 = x, y2 = y-1;
					y--;
					d = 1;
					break;
				case 'D':
					x1 = x-1, y1 = y, x2 = x, y2 = y;
					y++;
					d = 1;
					break;
			}
			if( x1>=0&&x1<n && y1>=0&&y1<m ) cut[x1][y1][d] = true;
			if( x2>=0&&x2<n && y2>=0&&y2<m ) cut[x2][y2][d-1] = true;
		}
		int cnt = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		if( !seen[i][j] )
		{
			bfs(i,j);
			cnt++;
		}
		return cnt;
	}
};
