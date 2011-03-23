#include <stdio.h>

#define MAX 100

int n, m, l, r, t, c, i, T[MAX], C[MAX], ans;

int main()
{
	for( i = 0; i < MAX; i++ ) T[i] = 11111;
	scanf( "%d%d", &n, &m );
	while( m-- )
	{
		scanf( "%d%d%d%d", &l, &r, &t, &c );
		l--, r--;
		for( i = l; i <= r; i++ ) if( t < T[i] ) T[i] = t, C[i] = c;
	}
	for( i = 0; i < MAX; i++ ) ans += C[i];
	printf( "%d\n", ans );
	return 0;
}
