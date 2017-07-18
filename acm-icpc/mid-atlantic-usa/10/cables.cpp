#include <cmath>
#include <cstdio>
#include <set>
#include <utility>

using namespace std;

#define MAX 1000

int n, x[MAX], y[MAX];
set< pair<double,int> > q;
bool seen[MAX];

int main()
{
	while(1)
	{
		scanf( "%d", &n );
		if(!n) break;
		for( int i = 0; i < n; i++ ) scanf( "%d%d", &x[i], &y[i] );
		double ans = 0;
		q.insert(make_pair(0,0));
		while(!q.empty())
		{
			double d = q.begin()->first;
			int i = q.begin()->second;
			q.erase(q.begin());
			if(seen[i]) continue;
			seen[i] = true;
			ans += d;
			for( int j = 0; j < n; j++ ) q.insert( make_pair( hypot( x[i]-x[j], y[i]-y[j] ) , j ) );
		}
		printf( "%.2lf\n", ans );
		for( int i = 0; i < n; i++ ) seen[i] = false;
	}
	return 0;
}
