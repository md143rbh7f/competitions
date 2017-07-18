#include <stdio.h>

#define MAX 1000000

int p[MAX], i, j, k, l, m, n[6], ok, ans;

int main()
{
	for( i = 2; i < MAX; i++ ) p[i] = 1;
	for( i = 2; i < MAX; i++ ) if( p[i] )
	{
		for( j = 2*i; j < MAX; j+=i ) p[j] = 0;
		j = i, l = 0;
		while(j) n[l++] = j%10, j /= 10;
		ok = 1;
		for( k = l-2; k >= 0; k-- )
		{
			j = 0;
			for( m = 0; m < l; m++ ) j = 10*j+n[(l+k-m)%l];
			ok &= p[j];
		}
		if( ok ) ans++;
	}
	printf( "%d\n", ans );
	return 0;
}
