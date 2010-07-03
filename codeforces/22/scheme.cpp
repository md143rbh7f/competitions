#include <cstdio>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define MAX 100000

int n, c, j, g[MAX], end[MAX], ans[MAX];
bool hasp[MAX], seen[MAX];

void findEnd( int i )
{
	if( end[i]>-1 ) return;
	if( seen[i] ) end[i]=i;
	else
	{
		seen[i] = true;
		findEnd(g[i]);
		end[i] = end[g[i]];
	}
}

int main()
{
	scanf( "%d", &n );
	rep(i,n)
	{
		scanf( "%d", &j );
		g[i] = --j;
		hasp[j] = true;
		end[i] = -1;
	}
	rep(i,n) if( !hasp[i] )
	{
		findEnd(i);
		ans[c++] = i;
	}
	rep(i,n) if( !seen[i] )
	{
		findEnd(i);
		ans[c++] = i;
	}
	if( c==1 && end[ans[0]]==ans[0] ) puts( "0" );
	else
	{
		printf( "%d\n", c );
		rep(i,c) printf( "%d %d\n", end[ans[(i+1)%c]]+1, ans[i]+1 );
	}
	return 0;
}
