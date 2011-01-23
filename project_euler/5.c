#include <stdio.h>

int i, a, b, c, ans = 1;

int main()
{
	for( i = 1; i < 20; i++ )
	{
		a = i, b = ans;
		while(b) c = a%b, a = b, b = c;
		ans = ans*i/a;
	}
	printf( "%d\n", ans );
	return 0;
}
