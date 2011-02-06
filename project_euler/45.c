#include <stdio.h>

int c;
long long i, j, k, I, J, K;

int main()
{
	for( i = j = k = I = J = K = 1; c < 3; ++i, I = i*(i+1)/2 )
	{
		for( ; J < I; ++j, J = j*(3*j-1)/2 ) for( ; K < J; ++k, K = k*(2*k-1) );
		if( I==J && J==K ) c++;
	}
	printf( "%lld\n", I );
	return 0;
}
