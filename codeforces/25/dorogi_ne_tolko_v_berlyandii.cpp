#include <stdio.h>

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int n, a, b, p[1000], c, ca[1000], cb[1000], da[1000], db[1000];

int find( int x )
{
	int ptr = x;
	while( p[ptr]>-1 ) ptr = p[ptr];
	while( x != ptr )
	{
		int old = x;
		x = p[x];
		p[old] = ptr;
	}
	return ptr;
}

int merge( int x, int y )
{
	x = find(x), y = find(y);
	if( x!=y )
	{
		if( p[x]>p[y] )
		{
			int temp = x;
			x = y;
			y = temp;
		}
		p[x] += p[y];
		p[y] = x;
	}
	return -p[x];
}

int main()
{
	scanf( "%d", &n );
	rep(i,n) p[i] = -1;
	rep(i,n-1)
	{
		scanf( "%d%d", &a, &b );
		a--, b--;
		if( find(a)==find(b) ) ca[c] = a, cb[c] = b, c++;
		merge(a,b);
	}
	c = 0, a = find(0);
	rep(i,n)
	{
		b = find(i);
		if( b!=a )
		{
			da[c] = a, db[c] = b, c++;
			merge(a,b);
			a = find(a);
		}
	}
	printf( "%d\n", c );
	rep(i,c) printf( "%d %d %d %d\n", ca[i]+1, cb[i]+1, da[i]+1, db[i]+1 );
	return 0;
}
