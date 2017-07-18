#include <stdio.h>

#define MAX 999
#define MIN -MAX
#define N 1<<23

int a, b, n, m, best, ab, p[N];

int main()
{
	for( a = 2; a < N; a++ ) p[a] = 1;
	for( a = 2; a*a < N; a++ ) if(p[a]) for( b = 2*a; b < N; b+=a ) p[b] = 0;
	for( a = MIN; a <= MAX; a++ ) for( b = 0; b <= MAX; b++ )
	{
		for( n = 0, m = b; m>=0 && p[m]; ++n, m = n*n+a*n+b );
		if( n > best ) best = n, ab = a*b;
	}
	printf( "%d\n", ab );
	return 0;
}
