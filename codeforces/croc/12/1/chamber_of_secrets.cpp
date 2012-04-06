#include <cstdio>
#include <list>
#include <utility>

using namespace std;

#define N 1005

char grid[N][N];
int dist[N][2];

int main()
{
	int n, m;
	scanf( "%d%d", &n, &m );
	for( int i = 0; i < n; i++ ) scanf( "%s", grid[i] );

	for( int i = 0; i < n; i++ ) dist[i][0] = -1;
	for( int j = 0; j < m; j++ ) dist[j][1] = -1;

	list< pair<int,int> > q;
	dist[n-1][0] = 0;
	q.push_back( make_pair( n-1, 0 ) );
	while( !q.empty() )
	{
		pair<int,int> v = q.front();
		q.pop_front();
		if( v.second == 0 )
		{
			int i = v.first;
			for( int j = 0; j < m; j++ ) if( grid[i][j] == '#' && dist[j][1] == -1 )
			{
				dist[j][1] = dist[i][0] + 1;
				q.push_back( make_pair( j, 1 ) );
			}
		}
		else
		{
			int j = v.first;
			for( int i = 0; i < n; i++ ) if( grid[i][j] == '#' && dist[i][0] == -1 )
			{
				dist[i][0] = dist[j][1] + 1;
				q.push_back( make_pair( i, 0 ) );
			}
		}
	}

	printf( "%d\n", dist[0][0] );

	return 0;
}
