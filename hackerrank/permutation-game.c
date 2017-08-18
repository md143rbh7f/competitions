#include "stdio.h"

#define rep(i,n) for(i=0;i<n;i++)
#define L 15

int n, x[L], mem[1<<L];

int rec( int m )
{
	if( mem[m] > -1 ) return mem[m];
	int i, prev = -1, asc = 1;
	mem[m] = 0;
	rep(i,n) if( ( m >> i ) & 1 )
	{
		if( prev > x[i] ) asc = 0;
		prev = x[i];
	}
	if( asc ) return 0;
	rep(i,n) if( ( ( m >> i ) & 1 ) && !rec( m ^ ( 1 << i ) ) ) mem[m] = 1;
	return mem[m];
}

int main()
{
	int t, i, m;
	for( scanf( "%d", &t ); t; t-- )
	{
		scanf( "%d", &n );
		rep(i,n) scanf( "%d", &x[i] );
		rep(i,1<<n) mem[i] = -1;
		printf( "%s\n", rec( (1<<n)-1 ) ? "Alice" : "Bob" );
	}
}
