#include <algorithm>
#include <cstdio>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int n, m, ans, l[30][30];
char buf[30][30];

int main()
{
	scanf( "%d%d", &n, &m );
	rep(i,n) scanf( "%s", buf[i] );
	rep(i,n) for( int j = m-1; j >= 0; j-- ) if( buf[i][j]=='0' ) l[i][j] = 1 + l[i][j+1];
	rep(i,n) rep(j,m)
	{
		int len = 100;
		REP(I,i,n)
		{
			len = min( len, l[I][j] );
			if( !len ) break;
			ans = max( ans, 2*(len+I-i+1) );
		}
	}
	printf( "%d", ans );
	return 0;
}
