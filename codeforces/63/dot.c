#include <stdio.h>

#define rep(i,n) for(i=0;i<n;i++)
#define N 404

int x, y, n, d, vx[20], vy[20], mem[N][N];

int rec( int a, int b )
{
	if( a*a + b*b > d*d ) return 1;
	int *ans = &mem[a+N/2][b+N/2];
	if( *ans > -1 ) return *ans;
	int i;
	rep(i,n) if( !rec( a+vx[i], b+vy[i] ) ) return *ans = 1;
	return *ans = 0;
}

int main()
{
	int i, j;
	rep(i,N) rep(j,N) mem[i][j] = -1;
	scanf( "%d%d%d%d", &x, &y, &n, &d );
	for( i = 0; i < n; i++ ) scanf( "%d%d", &vx[i], &vy[i] );
	printf( rec(x,y) ? "Anton\n" : "Dasha\n" );
	return 0;
}
