#include "stdio.h"

#define N 55

int t, n, x, v, nim_value[N], next[N];

void partition( int want, int have, int min, int val )
{
	if( want == have )
	{
		next[val] = 1;
		return;
	}
	int i;
	for( i = min; i < want && i + have <= want; i++ ) partition( want, have + i, i + 1, val ^ nim_value[i] );
}

void precompute()
{
	int i, j;
	for( i = 3; i < N; i++ )
	{
		for( j = 0; j < N; j++ ) next[j] = 0;
		partition( i, 0, 1, 0 );
		for( j = 0; j < N && next[j]; j++ );
		nim_value[i] = j;
	}
}

int main()
{
	precompute();
	scanf( "%d", &t );
	while( t-- )
	{
		scanf( "%d", &n );
		for( v = 0; n; n-- ) scanf( "%d", &x ), v ^= nim_value[x];
		printf( "%s\n", v ? "ALICE" : "BOB" );
	}
	return 0;
}
