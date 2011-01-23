#include <stdio.h>

#define MAX 28123

int ok[MAX+1], s[MAX+1], i, j, ans;

int main()
{
	for( i = 1; i <= MAX; i++ ) for( j = 2*i; j <= MAX; j+= i ) s[j] += i;
	for( i = 1; i <= MAX; i++ ) if( s[i] > i ) for( j = MAX-i; j >= 0; j-- ) if( s[j] > j ) ok[i+j] = 1;
	for( i = 1; i <= MAX; i++ ) if( !ok[i] ) ans += i;
	printf( "%d\n", ans );
	return 0;
}
