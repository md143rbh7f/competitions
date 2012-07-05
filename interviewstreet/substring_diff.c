#include "stdio.h"

#define N 1505

char p[N], q[N];
int miss[N][N], len[N][N], t, i, j, k, *l, m, n;

void run()
{
	scanf( "%d%s%s", &k, p, q );
	for( n = 0; p[n]; n++ );

	m = 0;
	for( i = 0; i <= n; i++ ) miss[n][i] = miss[i][n] = len[n][i] = len[i][n] = 0;
	for( i = n-1; i >= 0; i-- ) for( j = n-1; j >= 0; j-- )
	{
		miss[i][j] = miss[i+1][j+1] + ( p[i] != q[j] );

		l = &len[i][j];
		for( *l = len[i+1][j+1] + 1; miss[i][j] - miss[i+*l][j+*l] > k; (*l)-- );
		if( *l > m ) m = *l;
	}

	printf( "%d\n", m );
}

int main()
{
	scanf( "%d", &t );
	while( t-- ) run();
};
