#include <stdio.h>

#define L 60

int s[L], i, j;
char buf[L];

int main()
{
	for( i = 0; i < 100; i++ )
	{
		scanf( "%s", buf+10 );
		for( j = L-1; j; j-- )
		{
			if( buf[j] ) s[j] += buf[j]-'0';
			s[j-1] += s[j]/10;
			s[j] %= 10;
		}
	}
	i = 0;
	while( !s[i] ) i++;
	for( j = 0; j < 10; j++ ) printf( "%d", s[i+j] );
	printf( "\n" );
	return 0;
}
