#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define PI 3.141592653589793238462
#define INF 1e11
#define N 225
#define M 55

struct point
{
	double x, y;

	point() {}
	point( double _x, double _y ) : x( _x ), y( _y ) {}

	inline point operator-( const point & o ) const
	{ return point( x - o.x, y - o.y ); }

	inline double operator%( const point & o ) const
	{ return x * o.y - o.x * y; }
};

double best[N][N];
bool good[N][N];
point c[N], p[M];

struct FencingPenguinsEasy
{
	double calculateMinArea( int n, int r, vector<int> px, vector<int> py )
	{
		rep(i,n)
		{
			double q = 2 * PI * i / n;
			c[i] = point( r * cos(q), r * sin(q) );
		}

		int m = px.size();
		rep(i,m) p[i] = point( px[i], py[i] );

		rep(i,n) rep(j,n) if( i != j )
		{
			bool & ok = good[i][j] = true;
			rep(k,m) if( ( c[j] - c[i] ) % ( p[k] - c[i] ) < 0 ) ok = false;
			if( ( i + 1 ) % n == j && !ok ) return -1;
			best[i][j] = ok ? 0 : INF;
		}

		double ans = INF;
		REP(d,1,n) rep(i,n)
		{
			int j = ( i + d ) % n;
			if( best[i][j] == INF ) continue;
			for( int k = ( j + 1 ) % n; k != i; k = ( k + 1 ) % n )
			{
				double a = best[i][j] + ( c[j] - c[i] ) % ( c[k] - c[i] ) / 2;
				if( good[j][k] && good[k][i] ) ans = min( ans, a );
				else if( good[j][k] ) best[i][k] = min( best[i][k], a );
				else if( good[k][i] ) best[k][j] = min( best[k][j], a );
			}
		}

		return ans < INF ? ans : -1;
	}
};
