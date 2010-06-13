#include <stdio.h>

#define MAX 1000

int p[2] = { 2, 5 }, f[MAX][MAX][2], m[MAX][MAX][2], n, i, j, k, l, ans, z, y;
char buf[2*MAX];

int main()
{
	scanf( "%d", &n );
	for( i = 0; i < n; i++ ) for( j = 0; j < n; j++ )
	{
		scanf( "%d", &l );
		if( !l ) z = 1, y = i;
		else for( k = 0; k < 2; k++ )
		while( l%p[k]==0 )
		{
			l /= p[k];
			f[i][j][k]++;
		}
	}
	for( i = 0; i < n; i++ ) for( j = 0; j < n; j++ )
	for( k = 0; k < 2; k++ )
	{
		if( i || j ) m[i][j][k] = 1111111;
		if( i && m[i-1][j][k]<m[i][j][k] ) m[i][j][k] = m[i-1][j][k];
		if( j && m[i][j-1][k]<m[i][j][k] ) m[i][j][k] = m[i][j-1][k];
		m[i][j][k] += f[i][j][k];
	}
	i = j = n-1, k = m[i][j][0] < m[i][j][1] ? 0 : 1, l = 2*(n-1), ans = m[i][j][k];
	// zero case
	if( z && 1<ans )
	{
		ans = 1;
		for( ; i > y; i-- ) buf[--l] = 'D';
		for( ; j > 0; j-- ) buf[--l] = 'R';
		for( ; i > 0; i-- ) buf[--l] = 'D';
	}
	else while( i || j )
	{
		if( i && m[i][j][k]==m[i-1][j][k]+f[i][j][k] )
		{
			i--;
			buf[--l] = 'D';
		}
		else
		{
			j--;
			buf[--l] = 'R';
		}
	}
	printf( "%d\n%s\n", ans, buf );
	return 0;
}
