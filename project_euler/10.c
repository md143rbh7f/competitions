#include <stdio.h>

#define MAX 2000000

int p[MAX], i, j;
long long ans;

int main()
{
	for( i = 2; i < MAX; i++ ) p[i] = 1;
	for( i = 2; i*i < MAX; i++ ) if(p[i]) for( j = 2*i; j < MAX; j+=i ) p[j] = 0;
	for( i = 2; i < MAX; i++ ) if(p[i]) ans += i;
	printf( "%lld\n", ans );
	return 0;
}
