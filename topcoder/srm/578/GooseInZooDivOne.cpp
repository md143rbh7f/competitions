#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define all(i) (i).begin(),(i).end()
#define aall(i) (i),((i)+sizeof(i)/sizeof((i)[0]))
#define CLR(i,n) memset(i,n,sizeof(i))
#define clr(i) CLR(i,0)
#define M(x) ((x)%MOD)

#define MOD 1000000007
#define N 55

vs g;
int d, n, m, ways[2];
bool seen[N][N];

bool dfs( int x, int y )
{
	seen[x][y] = true;
	bool par = 1;
	REP(i,max(x-d,0),min(x+d+1,n)) REP(j,max(y-d,0),min(y+d+1,m))
	if( abs( x - i ) + abs( y - j ) <= d && g[i][j] == 'v' && !seen[i][j] )
		par ^= dfs( i, j );
	return par;
}

struct GooseInZooDivOne
{
	int count( vs _g, int _d )
	{
		g = _g, d = _d, n = g.size(), m = g[0].size(), ways[0] = 1;
		rep(i,n) rep(j,m) if( g[i][j] == 'v' && !seen[i][j] )
		{
			if( dfs( i, j ) ) ways[0] = ways[1] = M( ways[0] + ways[1] );
			else ways[0] = M( 2 * ways[0] ), ways[1] = M( 2 * ways[1] );
		}
		return ways[0] - 1;
	}
};
