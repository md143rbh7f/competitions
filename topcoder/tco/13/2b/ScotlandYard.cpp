#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define N 55
#define INF 100500
#define ON_STACK 1
#define DONE 2

vector<vs> g;
int n, state[N][N], mem[N][N];
bool has_next[N];

int rec( int i, int j )
{
	int & s = state[i][j], & ans = mem[i][j];
	if( s == ON_STACK ) s = DONE, ans = INF;
	if( s == DONE ) return ans;
	s = ON_STACK, ans = has_next[i] || has_next[j];
	foreach(h,g)
	rep(k,n) if( (*h)[i][k] == 'Y' || (*h)[j][k] == 'Y' )
	REP(l,k+1,n) if( (*h)[i][l] == 'Y' || (*h)[j][l] == 'Y' )
		ans = max( ans, 1 + rec( k, l ) );
	s = DONE;
	return ans;
}

struct ScotlandYard
{
	int maxMoves( vs a, vs b, vs c )
	{
		g.push_back( a ), g.push_back( b ), g.push_back( c );
		n = a.size();
		foreach(h,g) rep(i,n) rep(j,n) has_next[i] |= (*h)[i][j] == 'Y';
		int ans = 0;
		rep(i,n) REP(j,i+1,n) ans = max( ans, rec( i, j ) );
		return ans >= INF ? -1 : ans;
	}
};
