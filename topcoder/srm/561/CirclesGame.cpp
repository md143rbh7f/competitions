#include <cmath>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define N 55

vector<int> g[N];
int mem[N];

int nim( int v )
{
	int & ans = mem[v];
	if( ans != -1 ) return ans;
	int root = 0;
	for( int i = 0; i < g[v].size(); i++ ) root ^= nim( g[v][i] );
	set<int> choices;
	choices.insert( root );
	for( int i = 0; i < g[v].size(); i++ )
	{
		int c = nim( g[v][i] );
		root ^= c;
		for( int j = 0; j < c; j++ ) choices.insert( root ^ j );
		root ^= c;
	}
	for( ans = 0; choices.count(ans); ans++ );
	return ans;
}

struct CirclesGame
{
	string whoCanWin( vector<int> x, vector<int> y, vector<int> r )
	{
		int n = x.size();
		r.push_back( 1000000000 );
		for( int i = 0; i < n; i++ )
		{
			mem[i] = -1;
			int p = n;
			for( int j = 0; j < n; j++ )
			if( r[i] < r[j] && r[j] < r[p] && hypot( x[i] - x[j], y[i] - y[j] ) < r[j] )
				p = j;
			g[p].push_back( i );
		}
		int ans = 0;
		for( int i = 0; i < g[n].size(); i++ ) ans ^= nim( g[n][i] );
		return ans ? "Alice" : "Bob";
	}
};
