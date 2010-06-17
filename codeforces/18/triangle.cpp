#include <cstdio>

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

int c[3][2], x0, x1, y0, y1;

int right()
{
	rep(i,3)
	{
		int j = (i+1)%3, k = (i+2)%3;
		x0 = c[i][0]-c[j][0], y0 = c[i][1]-c[j][1];
		x1 = c[i][0]-c[k][0], y1 = c[i][1]-c[k][1];
		if( (x0||y0) && (x1||y1) && !(x0*x1+y0*y1) ) return 1;
	}
	return 0;
}

int main()
{
	rep(i,3) rep(j,2) scanf( "%d", &c[i][j] );
	if( right() )
	{
		printf( "RIGHT" );
		return 0;
	}
	else rep(i,3) rep(j,2)
	{
		c[i][j] -= 1;
		if( right() )
		{
			printf( "ALMOST" );
			return 0;
		}
		c[i][j] += 2;
		if( right() )
		{
			printf( "ALMOST" );
			return 0;
		}
		c[i][j] -= 1;
	}
	printf( "NEITHER" );
	return 0;
}
