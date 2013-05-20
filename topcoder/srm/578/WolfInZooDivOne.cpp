#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define M(x) ((x)%MOD)
#define MOD 1000000007

#define N 305

int _ways[N][N], (*ways)[N] = _ways + 2, l[N], r[N];
bool _e[N][N], (*e)[N] = _e + 2;

int parse( vs & in, int * out )
{
	stringstream ss;
	foreach( str, in ) ss << * str;
	int m = 0;
	while( ss >> out[m] ) m++;
	return m;
}

struct WolfInZooDivOne
{
	int count( int n, vs _l, vs _r )
	{
		int m = parse( _l, l );
		parse( _r, r );

		rep(i,m) REP(j,l[i],r[i]+1) REP(k,j,r[i]+1) e[j][k] = true;

		int ans = 0;
		ways[-1][-1] = 1;
		REP(i,-1,n) REP(j,i,n)
		{
			ans = M( ans + ways[i][j] );
			REP(k,j+1,n) if( !e[i][k] )
				ways[j][k] = M( ways[j][k] + ways[i][j] );
		}
		return ans;
	}
};
