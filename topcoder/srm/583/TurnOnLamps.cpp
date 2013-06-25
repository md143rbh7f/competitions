#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 55

vi g[N];
vector<bool> start[N], need[N];
int odd[N];

void add_edge( int a, int b, bool s, bool n )
{
	g[a].push_back( b );
	start[a].push_back( s );
	need[a].push_back( n );
}

int rec( int v, int p = -1 )
{
	int ans = 0, & cnt = odd[v];
	rep(i,g[v].size())
	{
		int u = g[v][i];
		if( u == p ) continue;
		ans += rec( u, v );
		if( need[v][i] )
		{
			if( !start[v][i] ) cnt++, ans += !odd[u];
		}
		else if( odd[u] ) cnt++;
	}
	ans -= cnt / 2, cnt %= 2;
	return ans;
}

struct TurnOnLamps
{
	int minimize( vi r, string s, string n )
	{
		rep(i,r.size())
		{
			s[i] -= '0', n[i] -= '0';
			add_edge( i + 1, r[i], s[i], n[i] );
			add_edge( r[i], i + 1, s[i], n[i] );
		}
		return rec(0);
	}
};
