#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 55

int d[N][N];

int cnt( int n )
{
	if( n == 1 ) return 0;
	return 1 + cnt( n - ( n + 1 ) / 3 );
}

struct DancingFoxes
{
	int minimalDays( vs g )
	{
		int n = g.size();
		rep(i,n) rep(j,n) d[i][j] = g[i][j] == 'Y' ? 1 : n;
		rep(k,n) rep(i,n) rep(j,n) d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
		return d[0][1] == n ? -1 : cnt( d[0][1] );
	}
};
