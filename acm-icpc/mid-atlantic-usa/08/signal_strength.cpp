#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define N 1005

int T;
vector<int> g[N];
vector<double> w[N];
double mem[N], coeff[N];
bool seen[N];

double rec( int i )
{
	double & ans = mem[i];
	if( seen[i] ) return ans;
	seen[i] = true;
	if( i == 0 ) return ans = coeff[0];
	ans = 0;
	double best = 0;
	for( int j = 0; j < g[i].size(); j++ )
		best = max( best, w[i][j] * rec( g[i][j] ) );
	return ans = coeff[i] * best;
}

bool run()
{
	int n;
	scanf( "%d", &n );
	if( !n ) return false;

	for( int i = 0; i < n; i++ ) g[i].clear(), w[i].clear();
	for( int i = 0; i < n; i++ )
	{
		int m;
		scanf( "%lf%d", &coeff[i], &m );
		for( int j = 0; j < m; j++ )
		{
			int k;
			double d;
			scanf( "%d%lf", &k, &d );
			g[k].push_back(i), w[k].push_back(d);
		}
	}

	for( int i = 0; i < n; i++ ) seen[i] = false;

	printf( "Network %d: %.2lf\n", T, rec( n - 1 ) );

	return true;
}

int main()
{
	for( T = 1; run(); T++ );
	return 0;
}
