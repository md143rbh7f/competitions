#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define bit(mask,i) ((mask>>i)&1)

#define INF 123456789
#define N 16

int n, m, cnt;
bool g[N][N], _h[N][N], (*h)[N] = _h + 2;

inline void move1( int i, int j )
{
	h[i-1][j] ^= 1, h[i][j-1] ^= 1, h[i+1][j] ^= 1, h[i][j+1] ^= 1;
}

inline void move2( int i, int j )
{
	h[i][j] ^= 1, move1( i, j );
}

void (*move[2])( int, int ) = { move1, move2 };

int work( int mask, int start )
{
	rep(i,n) rep(j,m) h[i][j] = g[i][j];
	int cnt = 0;
	rep(j,m) if( bit( start, j ) ) move[ bit( mask, j ) ]( 0, j ), cnt++;
	rep(i,n-1)
	{
		int used = 0;
		rep(j,m) if( h[i][j] )
		{
			cnt++;
			move[ bit( mask, j ) ]( i + 1, j );
			used |= 1 << bit( mask, j );
		}
		if( used == 3 ) return INF;
	}
	rep(j,m) if( h[n-1][j] ) return INF;
	return cnt;
}

struct YetAnotherBoardGame
{
	int minimumMoves( vs _g )
	{
		n = _g.size(), m = _g[0].size();
		rep(i,n) rep(j,m) g[i][j] = _g[i][j] == 'W';
		int M = 1 << m, ans = INF;
		rep(i,M)
		{
			ans = min( ans, work( i, 0 ) );
			for( int j = i; j; j = (j-1)&i ) ans = min( ans, work( i, j ) );
			int I = i ^ ( M - 1 );
			for( int j = I; j; j = (j-1)&I ) ans = min( ans, work( i, j ) );
		}
		return ans == INF ? -1 : ans;
	}
};
