#include <stdio.h>

#define MIN 1000
#define MAX 10000

int i, j, k, l[10], m, p[MAX], ok;

int perm( int x, int y )
{
	ok = 1;
	for( m = x; m; m/=10 ) l[m%10]++;
	for( m = y; m; m/=10 ) l[m%10]--;
	for( m = 0; m < 10; m++ ) ok &= !l[m], l[m] = 0;
	return ok;
}

int main()
{
	for( i = 2; i < MAX; i++ ) p[i] = 1;
	for( i = 2; i*i < MAX; i++ ) if(p[i]) for( j = 2*i; j < MAX; j+=i ) p[j] = 0;
	for( i = MIN; i < MAX; i++ ) if(p[i])
	for( j = i+1; ( k = 2*j-i ) < MAX; j++ ) if( p[j] && p[k] && perm(i,j) && perm(i,k) && ( i!= 1487 || j!=4817 ) ) printf( "%d%d%d\n", i, j, k );
	return 0;
}
