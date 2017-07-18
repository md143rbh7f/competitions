#include <stdio.h>

long long i = 2, n = 600851475143;

int main()
{
	while( i < n )
	{
		while( (n%i)==0 ) n /= i;
		i++;
	}
	printf( "%lld\n", i );
	return 0;
}
