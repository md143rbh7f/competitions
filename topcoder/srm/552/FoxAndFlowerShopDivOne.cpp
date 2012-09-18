#include <algorithm>
#include <cstring>
#include <list>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define clr(i,n) memset(i,n,sizeof(i))

#define N 33
#define D N*N

int sum[2][N][N], best[N][2*D];
char c[] = { 'L', 'P' };

inline int rect( int a[N][N], int i0, int i1, int j0, int j1 )
{
	i1++, j1++;
	return a[i1][j1] - a[i0][j1] - a[i1][j0] + a[i0][j0];
}

int run( vector<string> & f, int md )
{
	clr( sum, 0 ), clr( best, -1 );

	int n = f.size(), m = f[0].size();

	rep(i,n) rep(j,m) rep(k,2)
		sum[k][i+1][j+1] = sum[k][i][j+1] + sum[k][i+1][j] - sum[k][i][j] + ( f[i][j] == c[k] );
	
	rep(i0,n) REP(i1,i0,n) rep(j0,m) REP(j1,j0,m)
	{
		int s0 = rect( sum[0], i0, i1, j0, j1 ), s1 = rect( sum[1], i0, i1, j0, j1 );
		best[j1][s0-s1+D] = max( best[j1][s0-s1+D], s0 + s1 );
	}

	REP(j1,1,m) rep(d,2*D)
		best[j1][d] = max( best[j1-1][d], best[j1][d] );
	
	rep(j,m)
	{
		list< pair< int, int > > q;
		rep(d,2*D+md)
		{
			if( d < 2*D )
			{
				while( !q.empty() && q.back().second <= best[j][d] ) q.pop_back();
				q.push_back( make_pair( d, best[j][d] ) );
			}
			if( q.front().first < d - 2 * md ) q.pop_front();
			if( d >= md ) best[j][d-md] = q.front().second;
		}
	}
	
	int ans = -1;
	rep(i0,n) REP(i1,i0,n) REP(j0,1,m) REP(j1,j0,m)
	{
		int s0 = rect( sum[0], i0, i1, j0, j1 ), s1 = rect( sum[1], i0, i1, j0, j1 ), test = best[j0-1][s1-s0+D];
		if( test != -1 ) ans = max( ans, test + s0 + s1 );
	}

	return ans;
}

struct FoxAndFlowerShopDivOne
{
	int theMaxFlowers( vector<string> f, int md )
	{
		int n = f.size(), m = f[0].size();
		vector<string> g( m, string( n, '.' ) );
		rep(i,n) rep(j,m) g[j][i] = f[i][j];
		return max( run( f, md ), run( g, md ) );
	}
};
