#include <list>
#include <string>
#include <vector>

using namespace std;

#define MAX 1<<20

char prev_move[MAX], move[] = { 'D', 'L', 'R', 'U' };
int prev[MAX], dx[] = { 1, 0, 0, -1 }, dy[] = { 0, -1, 1, 0 };
list<int> q;

struct BlindMazeSolve
{
	string getSolution( vector<string> maze )
	{
		int n = maze.size(), m = maze[0].size(), start = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) if( maze[i][j] != 'X' ) start |= 1 << ( i * m + j );
		q.push_back(start);
		prev_move[start] = 1;
		while(!q.empty())
		{
			int state = q.front();
			q.erase(q.begin());
			for( int d = 0; d < 4; d++ )
			{
				int next = 0;
				for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) if( 1 & ( state >> ( i * m + j ) ) )
				{
					int ii = i + dx[d], jj = j + dy[d];
					if( jj >= 0 )
					{
						if( ii >= 0 && ii < n && jj < m && maze[ii][jj] == '.' ) next |= 1 << ( ii * m + jj );
						else next |= 1 << ( i * m + j );
					}
				}
				if( prev_move[next] == 0 )
				{
					prev_move[next] = move[d];
					prev[next] = state;
					q.push_back(next);
				}
			}
		}
		if( prev_move[0] == 0 ) return "";
		string ans = "";
		for( int ptr = 0; ptr != start; ptr = prev[ptr] )
			ans = prev_move[ptr] + ans;
		return ans;
	}
};
