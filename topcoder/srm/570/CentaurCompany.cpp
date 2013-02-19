#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define N 40

double _p[N*2*2*N], (*p)[2][2*N] = ( double(*)[2][2*N] ) ( _p + N );
double _tmp[2*N], * tmp = _tmp + N;
int sz[N];
vector<int> g[N];

void merge( double * a, int s, double * b, double * c, int t )
{
	for( int i = -s; i <= s; i++ ) for( int j = -t; j <= t; j++ )
		tmp[i+j] += a[i] * ( b[j] + c[j] );
	for( int i = - s - t; i <= s + t; i++ )
		a[i] = tmp[i], tmp[i] = 0;
}

void rec( int u, int v )
{
	sz[v] = 1, p[v][0][0] = 0.5, p[v][1][1] = 0.5;
	foreach( w, g[v] ) if( *w != u )
	{
		rec( v, *w );
		merge( p[v][0], sz[v], p[*w][0], p[*w][1], sz[*w] );
		merge( p[v][1], sz[v], p[*w][0], p[*w][1] + 2, sz[*w] );
		sz[v] += sz[*w];
	}
}

struct CentaurCompany
{
	double getvalue( vector<int> a, vector<int> b )
	{
		int n = a.size() + 1;
		for( int i = 0; i < n - 1; i++ )
			g[a[i]].push_back( b[i] ), g[b[i]].push_back( a[i] );
		rec( 0, 1 );
		double ans = 0;
		for( int s = 2; s <= n; s++ )
			ans += ( p[1][0][s] + p[1][1][s] ) * ( s - 2 );
		return 2 * ans;
	}
};
