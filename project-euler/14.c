#include <stdio.h>

#define MAX 1000000

int l[MAX], i, ans;

int rec( int n )
{
	if(!l[n])
	{
		int d = 0;
		long long m = n;
		do
		{
			if(m%2) m = 3*m+1;
			else m = m/2;
			d++;
		}
		while( m >= MAX );
		l[n] = d+rec(m);
	}
	return l[n];
}

int main()
{
	l[1] = 1;
	for( i = 2; i < MAX; i++ )
	{
		rec(i);
		if( l[i] > l[ans] ) ans = i;
	}
	printf( "%d\n", ans );
	return 0;
}
