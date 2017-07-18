#include <stdio.h>

int t, s, a, b, c;

int main()
{
	scanf( "%d", &t );
	while(t--)
	{
		scanf( "%d", &s ), a = 100, b = -1;
		while(s--)
		{
			scanf( "%d", &c );
			if(c<a) a = c;
			if(c>b) b = c;
		}
		printf( "%d\n", 2*(b-a) );
	}
	return 0;
}
