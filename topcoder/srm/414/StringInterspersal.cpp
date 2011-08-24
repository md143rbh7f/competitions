#include <set>
#include <string>
#include <vector>

using namespace std;

int x[20];
char ans[1001];
vector<string> w;

bool comp( int a, int b )
{
	for( int i = 0; x[a]+i < w[a].size() && x[b]+i < w[b].size(); i++ )
	{
		int d = w[a][x[a]+i] - w[b][x[b]+i];
		if( d > 0 ) return false;
		if( d < 0 ) return true;
	}
	int d = w[a].size() - x[a] - w[b].size() + x[b];
	if( d < 0 ) return false;
	if( d > 0 ) return true;
	return a < b;
}

struct StringInterspersal
{
	string minimum( vector<string> _w )
	{
		w = _w;
		int n = w.size();
		set<int,bool(*)(int,int)> q(comp);
		for( int i = 0; i < n; i++ ) q.insert(i);
		for( int m = 0; ; m++ )
		{
			int best = *q.begin();
			if( x[best] == w[best].size() ) break;
			q.erase(best);
			ans[m] = w[best][x[best]++];
			q.insert(best);
		}
		return string(ans);
	}
};
