#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define all(i) (i).begin(),(i).end()

#define N 305
#define K 7

int n, c0[K], c1[K], d[N][N];

void parse( vs & t, int c[K] )
{
	rep(i,N) rep(j,N) d[i][j] = i == j ? 0 : N;
	stringstream ss( accumulate( all(t), string() ) );
	n = 1;
	for( int x; ss >> x; n++ ) d[x][n] = d[n][x] = 1;
	rep(k,n) rep(i,n) rep(j,n) d[i][j] = min( d[i][j], d[i][k] + d[k][j] );
	rep(i,n) REP(j,i+1,n) if( d[i][j] < K ) c[d[i][j]]++;
}

struct TreeUnion
{
	double expectedCycles( vs t0, vs t1, int k )
	{
		parse( t0, c0 ), parse( t1, c1 );
		int cnt = 0;
		REP(i,1,k-2) cnt += c0[i] * c1[k-2-i];
		return 2.0 * cnt / n / ( n - 1 );
	}
};
