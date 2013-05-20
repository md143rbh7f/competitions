#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define N 305

int _ways[N], *ways = _ways + 1, l[N], r[N];

int parse( vs in, int * out )
{
	stringstream ss;
	foreach( str, in ) ss << *str;
	int m = 0;
	while( ss >> out[m] ) m++;
	return m;
}

struct WolfInZooDivTwo
{
	int count( int n, vs _l, vs _r )
	{
		int m = parse( _l, l );
		parse( _r, r );
		ways[-1] = 1;
		REP(i,-1,n)
		{
			int end = n;
			rep(j,m) if( l[j] > i ) end = min( end, r[j] );
			REP(j,i+1,end+1) ways[j] = ( ways[j] + ways[i] ) % 1000000007;
		}
		return ways[n];
	}
};
