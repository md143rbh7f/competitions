#include <stdio.h>

#define MAX 1000000

int i, j, p[MAX], q[MAX/10], s[MAX/10], np, ans;

int main()
{
	for( i = 2; i < MAX; i++ ) p[i] = 1;
	for( i = 2; i < MAX; i++ ) if(p[i]) for( q[np++] = i, j = 2*i; j < MAX; j+=i ) p[j] = 0;
	for( i = 0; i < np; i++ ) for( j = 0; i+j < np && s[j]+q[i+j] < MAX; j++ ) s[j] += q[i+j], ans = p[s[j]] ? s[j] : ans;
	printf( "%d\n", ans );
	return 0;
}
