#include <algorithm>
#include <cstdio>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 5000000
#define INF 1e111

int n, x[MAX], v[MAX];
double d = 1e11, EPS = 1e-11, t, l, r, far[MAX];
bool seen, cross;

int main()
{
	scanf( "%d", &n );
	rep(i,n) scanf( "%d%d", &x[i], &v[i] );
	while( (d/=2)>EPS )
	{
		cross = false;
		l = INF, r = -INF;
		rep(i,n)
		{
			if( v[i]>0 ) r = max( r, (t+d)*v[i]+x[i] );
			far[i] = r;
		}
		for( int i = n-1; i>=0; i-- )
		{
			if( v[i]<0 ) l = min( l, (t+d)*v[i]+x[i] );
			if( l<far[i] ) seen = true, cross = true;
		}
		if( !cross ) t += d;
	}
	if( !seen ) t = -1;
	printf( "%0.11f", t );
	return 0;
}
