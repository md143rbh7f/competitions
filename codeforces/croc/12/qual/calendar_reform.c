#include "stdio.h"

int best[20000005], a, b, i, j, s;
long long tot;

int main()
{
	scanf( "%d%d", &a, &b );
	b += a;
	for( i = 1; i * i <= b; i++ )
	{
		s = i * i;
		for( j = s; j < b; j += s ) best[j] = s;
	}
	for( i = a; i < b; i++ ) tot += i / best[i];
	printf( "%lld\n", tot );
	return 0;
}
