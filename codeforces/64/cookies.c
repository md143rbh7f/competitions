#include <stdio.h>

int n, ans = 1, mod = 1000003;

int main()
{
	scanf( "%d", &n );
	if(n) while( --n ) ans = (ans*3)%mod;
	printf( "%d\n", ans );
	return 0;
}
