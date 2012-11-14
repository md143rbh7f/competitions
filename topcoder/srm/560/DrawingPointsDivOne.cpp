#include <algorithm>
#include <list>
#include <utility>
#include <vector>

using namespace std;

#define M 150
#define N 4*M

int d[N][N], s[N][N], dx[] = { -1, -1, 1, 1 }, dy[] = { -1, 1, -1, 1 };

bool ok( int m )
{
	for( int i = m%2; i + 2 < N; i += 2 ) for( int j = m%2; j + 2 < N; j += 2 )
		s[i+2][j+2] = ( d[i][j] <= m ) + s[i+2][j] + s[i][j+2] - s[i][j];
	
	int sz = 2 * ( m + 1 ), need = ( m + 1 ) * ( m + 1 );
	for( int i = m%2; i + sz < N; i += 2 ) for( int j = m%2; j + sz < N; j += 2 )
	if( s[i+sz][j+sz] - s[i+sz][j] - s[i][j+sz] + s[i][j] == need && d[i+m][j+m] )
		return false;
	
	return true;
}

struct DrawingPointsDivOne
{
	int maxSteps( vector<int> x, vector<int> y )
	{
		for( int i = 0; i < N; i++ ) for( int j = 0; j < N; j++ ) d[i][j] = -1;

		int n = x.size();
		list< pair<int,int> > q;
		for( int i = 0; i < n; i++ )
		{
			x[i] = 2 * ( x[i] + M ), y[i] = 2 * ( y[i] + M );
			d[x[i]][y[i]] = 0;
			q.push_back( make_pair( x[i], y[i] ) );
		}
		while( !q.empty() )
		{
			int i = q.front().first, j = q.front().second;
			q.pop_front();
			for( int dir = 0; dir < 4; dir++ )
			{
				int ii = i + dx[dir], jj = j + dy[dir];
				if( ii < 0 || ii >= N || jj < 0 || jj >= N || d[ii][jj] != -1 ) continue;
				d[ii][jj] = d[i][j] + 1;
				q.push_back( make_pair( ii, jj ) );
			}
		}

		int l = 0, r = M;
		while( l < r )
		{
			int m = ( l + r + 1 ) / 2;
			if( ok( m ) ) l = m;
			else r = m - 1;
		}
		return l == M ? -1 : l;
	}
};
