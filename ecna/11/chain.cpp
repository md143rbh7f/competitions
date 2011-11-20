#include <cstdio>

using namespace std;

int s, c, p, l;

int main()
{
	for( int case_num = 1; ; case_num++ )
	{
		scanf( "%d%d%d%d", &s, &c, &p, &l );
		if( !s && !c && !p && !l ) break;
		int x = 0, y = 0;
		for( int t = 1; ; t++ )
		{
			x = ( s - 1 + x ) % s;
			y = ( c - 1 + y ) % c;
			if( x == p && y == l )
			{
				printf( "Case %d: %d %d/%d\n", case_num, t / s, t % s, s );
				break;
			}
			if( x == 0 && y == 0 )
			{
				printf( "Case %d: Never\n", case_num );
				break;
			}
		}
	}
}
