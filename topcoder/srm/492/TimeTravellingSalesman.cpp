#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> edge;

set<edge> q;
vector<edge> g[1000];
bool seen[1000];
int a, b, d;
char x, y;

struct TimeTravellingSalesman
{
	ll determineCost( int n, vector<string> roads )
	{
		string str = "";
		for( int i = 0; i < roads.size(); i++ ) str += roads[i];
		istringstream iss(str);
		while( iss >> a >> x >> b >> y >> d )
		{
			g[a].push_back( make_pair( d, b ) );
			g[b].push_back( make_pair( d, a ) );
		}
		ll tot = 0;
		q.insert( make_pair(0,0) );
		while(!q.empty())
		{
			d = q.begin()->first, a = q.begin()->second;
			q.erase(q.begin());
			if(seen[a]) continue;
			seen[a] = true;
			n--;
			tot += d;
			for( int i = 0; i < g[a].size(); i++ ) q.insert( g[a][i] );
		}
		return n ? -1 : tot;
	}
};
