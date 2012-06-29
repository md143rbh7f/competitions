#include <cstdio>
#include <list>
#include <utility>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define N 100005

char wall[2][N];
int t[2][N];

int main()
{
	int n, k;
	scanf( "%d%d%s%s", &n, &k, wall[0], wall[1] );

	for( int i = 0; i < 2; i++ ) for( int j = 0; j <= n; j++ ) t[i][j] = -1;
	t[0][0] = 0;
	list< pair<int,int> > q;
	q.push_back( make_pair( 0, 0 ) );
	while(!q.empty())
	{
		int i = q.front().first, j = q.front().second, d = t[i][j] + 1;
		q.pop_front();

		list< pair<int,int> > next;
		next.push_back( make_pair( i, j + 1 ) );
		next.push_back( make_pair( i, j - 1 ) );
		next.push_back( make_pair( 1 - i, j + k ) );

		foreach( pt, next )
		{
			int ii = pt->first, jj = pt->second;
			if( d > jj || ( jj < n && wall[ii][jj] == 'X' ) ) continue;
			if( jj > n ) jj = n;
			if( t[ii][jj] != -1 ) continue;
			t[ii][jj] = d;
			q.push_back( make_pair( ii, jj ) );
		}
	}

	printf( t[0][n] != -1 || t[1][n] != -1 ? "YES\n" : "NO\n" );

	return 0;
}
