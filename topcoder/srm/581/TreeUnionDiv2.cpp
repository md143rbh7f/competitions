#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 9

int n, d0[N][N], d1[N][N], p[N];

void parse( vs & g, int d[N][N] )
{
	rep(i,n) rep(j,n) d[i][j] = i == j ? 0 : g[i][j] == 'X' ? 1 : N;
	rep(k,n) rep(i,n) rep(j,n) d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
}

struct TreeUnionDiv2
{
	int maximumCycles( vs g0, vs g1, int k )
	{
		n = g0.size();
		parse( g0, d0 ), parse( g1, d1 );
		rep(i,n) p[i] = i;
		int ans = 0;
		do
		{
			int c = 0;
			rep(i,n) REP(j,i+1,n) if( d0[i][j] + d1[p[i]][p[j]] == k - 2 ) c++;
			ans = max( ans, c );
		}
		while( next_permutation( p, p + n ) );
		return ans;
	}
};

