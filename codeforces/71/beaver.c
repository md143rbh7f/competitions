#include <stdio.h>

#define MAX 100010

int match[MAX], n, m, l, i, j, ok, len, pos;
char str[MAX], buf[11];

int main()
{
	scanf( "%s%d", str, &m );
	while(str[n]) n++;
	while(m--)
	{
		scanf( "%s", buf );
		for( l = 0; buf[l]; l++ );
		for( i = 0; i + l <= n; i++ )
		{
			ok = 1;
			for( j = 0; j < l; j++ ) if( str[i+j] != buf[j] ) ok = 0;
			if( ok && ( !match[i] || match[i] > l ) ) match[i] = l;
		}
	}
	l = 0;
	for( i = n-1; i >= 0; i-- )
	{
		l++;
		if( match[i] && match[i] - 1 < l ) l = match[i] - 1;
		if( l >= len )
		{
			len = l;
			pos = i;
		}
	}
	printf( "%d %d\n", len, pos );
	return 0;
}
