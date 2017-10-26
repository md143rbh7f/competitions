#include "stdio.h"

#define MAX 2005

char buf[MAX];
int good[MAX][MAX], len, i, j, left, right;
long long ans;

int main()
{
	scanf( "%s", buf );
	while( buf[++len] );
	for( i = 0; i < len; i++ ) good[i][i] = 1;
	for( i = 0; i + 1 < len; i++ ) good[i][i+1] = buf[i] == buf[i+1];
	for( j = 2; j < len; j++ ) for( i = 0; i + j < len; i++ ) good[i][i+j] = good[i+1][i+j-1] && ( buf[i] == buf[i+j] );
	for( i = 0; i + 1 < len; i++ )
	{
		for( j = 0; j <= i; j++ ) left += good[j][i];
		right = 0;
		for( j = i + 1; j < len; j++ ) right += good[i+1][j];
		ans += left * right;
	}
	printf( "%I64d\n", ans );
	return 0;
}
