#include <algorithm>
#include <cstdio>

using namespace std;

int p[9], i, j, k, l, ans;

int main()
{
	for( l = 1; l <= 9; l++ )
	{
		p[l-1] = l;
		do
		{
			k = 1;
			for( i = j = 0; i < l; j = j*10+p[i], i++ );
			for( i = 2; i*i <= j; i++ ) if( j%i == 0 )
			{
				k = 0;
				break;
			}
			if(k) ans = j;
		}
		while(next_permutation(p,p+l));
	}
	printf( "%d\n", ans );
	return 0;
}
