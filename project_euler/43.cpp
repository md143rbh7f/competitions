#include <algorithm>
#include <cstdio>

using namespace std;

int p[10], P[] = { 2, 3, 5, 7, 11, 13, 17 }, ok, i, j;
long long ans, k;

int main()
{
	for( i = 0; i < 10; i++ ) p[i] = i;
	do
	{
		ok = 1;
		for( j = 0; j < 7; j++ )
		{
			k = 100*p[j+1]+10*p[j+2]+p[j+3];
			if(k%P[j]) ok = 0;
		}
		if(ok)
		{
			for( i = k = 0; i < 10; i++ ) k = 10*k+p[i];
			ans += k;
		}
	}
	while( next_permutation( p, p+10 ) );
	printf( "%lld\n", ans );
	return 0;
}
