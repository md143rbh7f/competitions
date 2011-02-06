#include <stdio.h>

int c, i, j, k, l;

int main()
{
	for( i = 2; c < 4; i++ )
	{
		for( j = i, k = 2, l = 1; k*k <= j; k++ ) if(j%k==0)
		{
			l++;
			while(j%k==0) j /= k;
		}
		if(l>=4) c++;
		else c = 0;
	}
	printf( "%d\n", i-4 );
	return 0;
}
