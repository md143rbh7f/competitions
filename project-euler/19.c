#include <stdio.h>

int ans, d = 1, m = 1, y = 1900, w = 1, md[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	while( y<2001 )
	{
		if( w==0 && d==1 && y>=1901 ) ans++;
		d++;
		if( d==md[m]+1 ) m++, d = 1;
		if( d==md[m] && !( m==2 && y%4==0 && y!=1900 ) ) m++, d = 1;
		if( m==13 ) y++, m = 1;
		w = (w+1)%7;
	}
	printf( "%d\n", ans );
	return 0;
}
