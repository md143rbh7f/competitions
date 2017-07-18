#include <cmath>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

vector<int> g[12];
double x[12], y[12];
int n, col[12], T;
set<int> cols;

void rec( int x )
{
	if( col[x] ) return;
	for( col[x] = 1; col[x] <= n; col[x]++ )
	{
		bool ok = true;
		for( int y = 0; y < g[x].size(); y++ ) if( col[x] == col[g[x][y]] ) ok = false;
		if(!ok) continue;
		for( int y = 0; y < g[x].size(); y++ ) rec(g[x][y]);
		return;
	}
}

int main()
{
	while(1)
	{
		scanf( "%d", &n );
		if(!n) break;
		for( int i = 0; i < n; i++ ) scanf( "%lf%lf", &x[i], &y[i] );
		for( int i = 0; i < n; i++ ) g[i].clear();
		for( int i = 0; i < n; i++ ) for( int j = i+1; j < n; j++ )
		if( hypot( x[i]-x[j], y[i]-y[j] ) <= 20 )
			g[i].push_back(j), g[j].push_back(i);
		for( int i = 0; i < n; i++ ) col[i] = 0;
		for( int i = 0; i < n; i++ ) rec(i);
		cols.clear();
		for( int i = 0; i < n; i++ ) cols.insert( col[i] );
		printf( "The towers in case %d can be covered in %d frequencies.\n", ++T, (int) cols.size() );
	}
	return 0;
}
