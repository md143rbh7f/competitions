#include <cstdio>
#include <cstring>
#include <list>
#include <set>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define N 16
#define M 1<<N
#define MOD 1000000007

int x[N], y[N], ways[M], d[M];
bool collinear[M];

void run()
{
	int n;
	scanf( "%d", &n );
	for( int i = 0; i < n; i++ ) scanf( "%d%d", &x[i], &y[i] );

	int m = 1<<n;
	for( int s = 0; s < m; s++ )
	{
		collinear[s] = true;
		int i = -1, j = -1, x0, y0;
		for( int k = 0; k < n; k++ ) if( ( s >> k ) & 1 )
		{
			if( i == -1 ) i = k;
			else if( j == -1 ) j = k, x0 = x[j] - x[i], y0 = y[j] - y[i];
			else
			{
				int x1 = x[k] - x[i], y1 = y[k] - y[i];
				if( x0 * y1 != x1 * y0 ) collinear[s] = false;
			}
		}
	}

	memset( d, 0, sizeof(d) );
	memset( ways, 0, sizeof(ways) );
	list<int> q;
	q.push_back(0);
	ways[0] = 1;
	while( !q.empty() )
	{
		int s = q.front();
		if( s == m - 1 ) break;
		q.pop_front();

		int u = s|(s+1);
		for( int t = u; t < m; t = (t+1)|u ) if( collinear[t^s] )
		{
			if( !d[t] )
			{
				d[t] = d[s] + 1;
				q.push_back(t);
			}
			if( d[t] == d[s] + 1 ) ways[t] = ( ways[s] + ways[t] ) % MOD;
		}
	}

	long long ans = ways[m-1];
	for( int i = 1; i <= d[m-1]; i++ ) ans = ( i * ans ) % MOD;
	printf( "%d %lld\n", d[m-1], ans );
}

int main()
{
	int t;
	scanf( "%d", &t );
	while( t-- ) run();
	return 0;
}
