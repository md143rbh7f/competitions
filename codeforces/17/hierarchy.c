#include <stdio.h>

#define INF 1111111

int n, m, i, t, v, c, root, s, cost[1000];

int main()
{
	scanf( "%d", &n );
	for( i = 0; i < n; i++ ) scanf( "%d", &t );
	for( i = 0; i < n; i++ ) cost[i] = INF;
	scanf( "%d", &m );
	while( m-- )
	{
		scanf( "%d %d %d", &t, &t, &c );
		t--;
		if( cost[t] > c ) cost[t] = c;
	}
	for( i = 0; i < n; i++ )
		if( cost[i]==INF ) root++;
		else s += cost[i];
	if( root>1 ) s = -1;
	printf( "%d", s );
	return 0;
}
