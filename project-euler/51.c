#include <stdio.h>

#define MAX 1000000

int i, j, k, l, m, n, o, p[MAX], q[MAX/10], r, s, t, ans;

int main()
{
	for( i = 2; i < MAX; i++ ) p[i] = 1;
	for( i = 2; i < MAX; i++ ) if(p[i]) for( j = 2*i, q[n++] = i; j < MAX; j+=i ) p[j] = 0;
	for( i = 0, r = 1; i < n; i++ )
	{
		if(q[i]>r) r *= 10, s++;
		for( m = 0; m < 1<<s; m++ )
		{
			for( j = k = l = 0, o = 1; j < s; j++, o *= 10 ) if((m>>j)&1) k += o; else l += ((q[i]/o)%10)*o;
			for( j = o = t = 0; j < 10; j++ ) if( l+j*k>=q[i] && p[l+j*k] ) o++, t = t ? t : l+j*k;
			if( !ans && o==8 ) ans = t;
		}
	}
	printf( "%d\n", ans );
	return 0;
}
