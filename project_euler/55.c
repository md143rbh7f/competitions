#include <stdio.h>

#define L 50

int i, j, k, l, m, n[L], ans;

int main()
{
	for( i = 0; i < 10000; i++ )
	{
		for( k = i, l = 0; k; k /= 10 ) n[l++] = k%10;
		for( j = l; j < L; j++ ) n[j] = 0;
		for( j = 0; j < 50; j++ )
		{
			for( k = 0; k < (l+1)/2; k++ ) n[k] += n[l-k-1];
			for( ; k < l; k++ ) n[k] = n[l-k-1];
			for( k = 0; k < l; k++ ) n[k+1] += n[k]/10, n[k] %= 10;
			if(n[l]) l++;
			m = 1;
			for( k = 0; k < l; k++ ) m &= n[k]==n[l-k-1];
			if(m) break;
		}
		if(j==50) ans++;
	}
	printf( "%d\n", ans );
	return 0;
}
