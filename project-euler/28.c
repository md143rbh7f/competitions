#include <stdio.h>

#define N 1001

int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 }, x = N/2, y = N/2, d, n, s, ans;

int main()
{
	for( n = s = 1; n <= N*N; n++ )
	{
		if( n!=s*s && ( x==y || x+y==N-1 ) ) ans += n, d = (d+1)%4;
		x += dx[d], y += dy[d];
		if( n == s*s ) ans += n, s += 2, d = (d+1)%4;
	}
	printf( "%d\n", ans );
	return 0;
}
