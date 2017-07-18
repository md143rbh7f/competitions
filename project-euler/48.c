#include <stdio.h>

#define MAX 1000
#define L 10

int i, j, k, l[L+1], m, n, o[L+1], p[L][L+1], ans[L+1];

void mult( int a[], int b[], int c[] )
{
	for( m = 0; m < L; m++ ) for( n = 0; m + n < L; n++ ) o[m+n+1] += (o[m+n]+a[m]*b[n])/10, o[m+n] = (o[m+n]+a[m]*b[n])%10;
	for( m = 0; m < L; m++ ) c[m] = o[m], o[m] = 0;
}

int main()
{
	for( i = 1; i <= MAX; i++ )
	{
		for( j = 0, k = i; j < L; j++ ) p[0][j] = k%10, k /= 10;
		for( j = 1; j < L; j++ ) mult( p[j-1], p[j-1], p[j] );
		for( l[0] = 1, j = L-1, k = i; k; j-- ) if(k>=(1<<j)) mult( p[j], l, l ), k -= 1<<j;
		for( j = 0; j < L; j++ ) ans[j+1] += (ans[j]+l[j])/10, ans[j] = (ans[j]+l[j])%10, l[j] = 0;
	}
	for( j = L-1; j >= 0; j-- ) printf( "%d", ans[j] );
	printf( "\n" );
	return 0;
}
