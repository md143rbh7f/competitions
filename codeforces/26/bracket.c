#include <stdio.h>

#define MAX 1000001

char buf[MAX];
int n, i, j, ans, a[MAX], b[MAX], q;

int main()
{
	scanf( "%s", buf );
	while( n<MAX && buf[n] ) n++;
	for( i=0; i<n; i++ )
	{
		if( buf[i]=='(' ) a[q++] = i;
		else if( q ) b[a[--q]] = i;
	}
	for( i=0; i<n; i++ )
	{
		j = i;
		while( j<n && b[j] ) j = b[j]+1;
		ans += j-i, i = j;
	}
	printf( "%d", ans );
	return 0;
}
