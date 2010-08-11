#include <stdio.h>

int l[2], n, t, i;

int main()
{
	scanf( "%d", &n );
	for( i=1; i<=n; i++ )
	{
		scanf( "%d", &t );
		t %= 2;
		if( !l[t] ) l[t] = i;
		else l[t] = -1;
	}
	for( i=0; i<2; i++ ) if( l[i]!=-1 ) printf( "%d", l[i] );
	return 0;
}
