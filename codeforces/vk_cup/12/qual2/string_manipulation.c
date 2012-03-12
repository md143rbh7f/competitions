#include "stdio.h"

char buf[105], c[2];
int i, j, k, l, m, n, tree[26][200005];

void add( int a, int x, int amt )
{
	for( ; x <= l; x += x&(-x) ) tree[a][x] += amt;
}

int freq( int a, int x )
{
	int ans = tree[a][x], end = x - (x&(-x));
	for( x--; x > end; x -= x&(-x) ) ans -= tree[a][x];
	return ans;
}

int find( int a, int cf )
{
	int ans = 0, del = 1<<18;
	for( ; del; del >>= 1 ) if( ans+del <= l && tree[a][ans+del] < cf )
	{
		ans += del;
		cf -= tree[a][ans];
	}
	return ans;
}

int main()
{
	scanf( "%d%s%d", &k, buf, &n );
	while(buf[++m]);
	l = k * m;
	for( i = 0; i < l; i++ ) add( buf[i%m]-'a', i+1, 1 );
	while(n--)
	{
		scanf( "%d%s", &i, c );
		j = find( c[0]-'a', i );
		add( c[0]-'a', j+1, -1 );
	}
	for( i = 0; i < l; i++ ) if( freq( buf[i%m]-'a', i+1 ) ) putchar(buf[i%m]);
	putchar('\n');
	return 0;
}
