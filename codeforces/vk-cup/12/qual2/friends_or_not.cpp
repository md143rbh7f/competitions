#include <iostream>
#include <list>
#include <map>
#include <string>
#include <set>
#include <utility>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

typedef pair<string,string> edge;

edge e, f;
string a, b;
map< edge, list<int> > last;
set<edge> friends;
int n, d, m, t;

int main()
{
	cin >> n >> d;
	for( int i = 0; i < n; i++ )
	{
		cin >> a >> b >> t;
		e = make_pair(a,b), f = make_pair(b,a);
		last[e].push_front(t);
		while( !last[f].empty() && last[f].back() < t - d ) last[f].pop_back();
		if( !last[f].empty() && last[f].back() < t ) friends.insert(a<b?e:f);
	}
	cout << friends.size() << endl;
	foreach(it,friends) cout << it->first << " " << it->second << endl;
	return 0;
}
