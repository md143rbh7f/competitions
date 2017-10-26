#include "stdio.h"

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int c[5], n, i, s, ans;

int main()
{
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
	{
		scanf( "%d", &s );
		c[s]++;
	}
	int min13 = min(c[1],c[3]);
	ans = c[4] + c[2] / 2 + min13;
	c[4] = 0;
	c[3] -= min13;
	c[2] %= 2;
	c[1] -= min13;
	if( c[3] )
	{
		ans += c[3];
		c[3] = 0;
	}
	if( c[2] )
	{
		ans++;
		c[2] = 0;
		c[1] = max(0,c[1]-2);
	}
	ans += ( c[1] + 3 ) / 4;
	c[1] = 0;
	printf( "%d\n", ans );
	return 0;
}
