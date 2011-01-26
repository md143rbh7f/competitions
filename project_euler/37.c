#include <stdio.h>

#define MAX 1000000

int p[MAX], i, j, k, ok, ans;

int main()
{
	for( i = 2; i < MAX; i++ ) p[i] = 1;
	for( i = 2; i < MAX; i++ ) if(p[i])
	{
		for( j = 2*i; j < MAX; j+=i ) p[j] = 0;
		ok = i>=10;
		for( j = i; j; j /= 10) ok &= p[j];
		for( k = MAX; k >= 10; k /= 10 ) ok &= p[i%k];
		if(ok) ans += i;
	}
	printf( "%d\n", ans );
	return 0;
}
