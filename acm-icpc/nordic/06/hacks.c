#include <stdio.h>

int cases, r, e, c, r2;

int main()
{
	scanf( "%d", &cases );
	while(cases--)
	{
		scanf( "%d%d%d", &r, &e, &c );
		r2 = e-c;
		if(r>r2) printf( "do not advertise\n" );
		else if(r<r2) printf( "advertise\n" );
		else printf( "does not matter\n" );
	}
	return 0;
}
