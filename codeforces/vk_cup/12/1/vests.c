#include "stdio.h"

#define MAX 100005

long long a[MAX], b[MAX], x, y;
int n, m, i, j, ans, ans_a[MAX], ans_b[MAX];

int main()
{
	scanf( "%d%d%lld%lld", &n, &m, &x, &y );
	for( i = 0; i < n; i++ ) scanf( "%lld", &a[i] );
	for( j = 0; j < m; j++ ) scanf( "%lld", &b[j] );
	i = j = 0;
	while( i < n && j < m )
	{
		if( a[i] - x <= b[j] && b[j] <= a[i] + y )
		{
			i++, j++;
			ans_a[ans] = i, ans_b[ans] = j;
			ans++;
		}
		else if( a[i] + y < b[j] ) i++;
		else if( b[j] < a[i] - x ) j++;
	}
	printf( "%d\n", ans );
	for( i = 0; i < ans; i++ ) printf( "%d %d\n", ans_a[i], ans_b[i] );
	return 0;
}
