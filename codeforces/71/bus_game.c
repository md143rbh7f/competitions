#include <stdio.h>

int x, y;

int main()
{
	scanf( "%d%d", &x, &y );
	while(1)
	{
		if( x >= 2 && y >= 2 ) x -= 2, y -= 2;
		else if( x >= 1 && y >= 12 ) x -= 1, y -= 12;
		else if( y >= 22 ) y -= 22;
		else
		{
			printf( "Hanako\n" );
			break;
		}
		if( y >= 22 ) y -= 22;
		else if( x >= 1 && y >= 12 ) x -= 1, y -= 12;
		else if( x >= 2 && y >= 2 ) x -= 2, y -= 2;
		else
		{
			printf( "Ciel\n" );
			break;
		}
	}
	return 0;
}
