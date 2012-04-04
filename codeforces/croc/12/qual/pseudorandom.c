#include "stdio.h"

int t[100005], a, b, m, r, s;

int main()
{
	scanf( "%d%d%d%d", &a, &b, &m, &r );
	for( ; !t[r]; r = ( a * r + b ) % m ) t[r] = ++s;
	printf( "%d\n", s - t[r] + 1 );
	return 0;
}
