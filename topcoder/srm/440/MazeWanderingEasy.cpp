#include <string>
#include <vector>

using namespace std;

int n, m, dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
vector<string> g;
bool seen[50][50];

int rec( int i, int j )
{
	if( g[i][j] == '*' ) return 0;
	seen[i][j] = true;
	int cnt = 0, ans = -1;
	for( int d = 0; d < 4; d++ )
	{
		int ii = i+dx[d], jj = j+dy[d];
		if( ii >= 0 && ii < n && jj >= 0 && jj < m && !seen[ii][jj] && g[ii][jj] != 'X' )
		{
			cnt++;
			int tmp = rec(ii,jj);
			if( tmp != -1 ) ans = tmp;
		}
	}
	return ans > -1 ? ans + ( cnt > 1 ) : -1;
}

struct MazeWanderingEasy
{
	int decisions( vector<string> maze )
	{
		g = maze;
		n = g.size(), m = g[0].size();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		if( g[i][j] == 'M' )
			return rec(i,j);
		return -1;
	}
};
