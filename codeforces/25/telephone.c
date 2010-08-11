#include <stdio.h>

int n, i;
char buf[100];

int main()
{
	scanf( "%d%s", &n, buf );
	for( i=0; i<n; i++ )
	{
		putchar(buf[i]);
		if( i%2 && i<n-(n%2)-2 ) putchar('-');
	}
	return 0;
}
