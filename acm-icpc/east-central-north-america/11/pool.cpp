#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	int a, b;
	for( int case_num = 1; ; case_num++ )
	{
		scanf( "%d%d", &a, &b );
		if( !a && !b ) break;
		int k = 0;
		for( long long n = 1; ; n++ )
		{
			long long x = n * ( n - 1 ) / 2;
			if( x + 1 >= b ) break;
			if( x + 1 > a )
			{
				long long root = sqrt( x + 1 );
				if( root * root == x + 1 ) k++;
			}
		}
		printf( "Case %d: %d\n", case_num, k );
	}
}
