#include <cstdio>

using namespace std;

#define N 505
#define blade(a,b) a[i+s][j+s] - a[i+s][j] - a[i][j+s] + a[i][j] - b[i][j] - b[i+s-1][j] - b[i][j+s-1] - b[i+s-1][j+s-1]
#define accumulate(a,b) a[i+1][j+1] = a[i][j+1] + a[i+1][j] - a[i][j] + b[i][j]

struct point
{
	int x, y;
	point( int _x = 0, int _y = 0 ) : x(_x), y(_y) {}
};

inline bool operator==( point a, point b ) { return a.x == b.x && a.y == b.y; }
inline point operator+( point a, point b ) { return point( a.x + b.x, a.y + b.y ); }
inline point operator-( point a, point b ) { return point( a.x - b.x, a.y - b.y ); }
inline point operator*( int a, point b ) { return point( a * b.x, a * b.y ); }

char buf[N][N];
int T, R, C, D, t, i, j, k, s, mass[N][N], sum_mass[N][N];
point rot[N][N], sum_rot[N][N];

int main()
{
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		scanf( "%d%d%d", &R, &C, &D );
		for( i = 0; i < R; i++ ) scanf( "%s", buf[i] );
		for( i = 0; i < R; i++ ) for( j = 0; j < C; j++ )
		{
			mass[i][j] = buf[i][j] - '0';
			rot[i][j] = mass[i][j] * point( i, j );
			accumulate( sum_mass, mass ), accumulate( sum_rot, rot );
		}
		for( s = R < C ? R : C; s >= 3; s-- ) for( i = 0; i + s <= R; i++ ) for( j = 0; j + s <= C; j++ )
		{
			int tot_mass = blade( sum_mass, mass );
			point tot_rot = blade( sum_rot, rot );
			if( 2 * tot_rot == tot_mass * point( 2 * i + s - 1, 2 * j + s - 1 ) )
			{
				printf( "Case #%d: %d\n", t, s );
				goto done;
			}
		}
		printf( "Case #%d: IMPOSSIBLE\n", t );
		done:;
	}
	return 0;
}
