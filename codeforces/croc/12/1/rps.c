#include "stdio.h"
#include "string.h"

#define N 1005
#define R 1000005

int n, m, nm, r, i, j, k, lose_a[R], lose_b[R];
char a[N], b[N];

int play( char x, char y )
{
	if( x == y ) return 0;
	if( ( x == 'R' && y == 'P' ) || ( x == 'P' && y == 'S' ) || ( x == 'S' && y == 'R' ) ) return -1;
	return 1;
}

int main()
{
	scanf( "%d%s%s", &r, a, b );
	n = strlen(a), m = strlen(b);
	nm = n * m;
	for( k = 1; k <= nm; k++ )
	{
		int res = play( a[i], b[j] );
		lose_a[k] = lose_a[k-1] + ( res == -1 );
		lose_b[k] = lose_b[k-1] + ( res == 1 );
		i = ( i + 1 ) % n;
		j = ( j + 1 ) % m;
	}
	printf( "%d %d\n", r / nm * lose_a[nm] + lose_a[r%nm], r / nm * lose_b[nm] + lose_b[r%nm] );
	return 0;
}
