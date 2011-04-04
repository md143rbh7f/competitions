#include <stdio.h>

#define L 151

long long q;
int N, n, f[4], F, e[4], i, j, k, p;
char out[L];

int main()
{
	scanf( "%d", &N );
	while(N--)
	{
		scanf( "%d", &n );
		F = 1;
		for( i = 0; i < 4; i++ )
		{
			scanf( "%d", &f[i] );
			F *= f[i];
		}
		for( i = 0; i < 4; i++ )
		{
			k = F/f[i];
			e[i] = 0;
			while( (e[i]%f[i])!=1 ) e[i] += k;
		}
		for( i = 0; i < n; i++ )
		{
			scanf( "%d", &p );
			q = 0;
			for( j = 3; j >= 0; j-- )
			{
				q = ( q + ((long long)p%100)*e[j] )%F;
				p /= 100;
			}
			for( j = 2; j >= 0; j-- )
			{
				out[3*i+j] = (q%100)==27 ? ' ' : (q%100)+'A'-1;
				q /= 100;
			}
		}
		out[3*n] = 0;
		for( i = 3*n-1; i >= 0 && out[i]==' '; i-- ) out[i] = 0;
		printf( "%s\n", out );
	}
	return 0;
}
