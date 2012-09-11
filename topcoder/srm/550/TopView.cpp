#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

struct TopView
{
	string findOrder( vector<string> grid )
	{
		set<char> v;
		map<char,int> x0, x1, y0, y1;
		int n = grid.size(), m = grid[0].size();
		for( int x = 0; x < n; x++ )
		for( int y = 0; y < m; y++ )
		if( grid[x][y] != '.' )
		{
			char c = grid[x][y];
			v.insert(c);
			if( !x0.count(c) || x < x0[c] ) x0[c] = x;
			if( !x1.count(c) || x > x1[c] ) x1[c] = x;
			if( !y0.count(c) || y < y0[c] ) y0[c] = y;
			if( !y1.count(c) || y > y1[c] ) y1[c] = y;
		}

		map< char, set<int> > g;
		foreach( c, v )
		for( int x = x0[*c]; x <= x1[*c]; x++ )
		for( int y = y0[*c]; y <= y1[*c]; y++ )
		if( grid[x][y] != *c && grid[x][y] != '.' )
			g[*c].insert( grid[x][y] );

		map<char,int> p;
		foreach( c, v ) foreach( d, g[*c] )
			p[*d]++;

		set<char> q;
		foreach( c, v ) if( p[*c] == 0 )
			q.insert( *c );

		string ans;
		while( !q.empty() )
		{
			char c = *q.begin();
			q.erase(c);
			ans += c;
			foreach( d, g[c] )
			{
				p[*d]--;
				if( !p[*d] ) q.insert( *d );
			}
		}
		if( ans.size() < v.size() ) return "ERROR!";

		vector<string> test( n, string( m, '.' ) );
		foreach( c, ans )
		for( int x = x0[*c]; x <= x1[*c]; x++ )
		for( int y = y0[*c]; y <= y1[*c]; y++ )
			test[x][y] = *c;
		if( test != grid ) return "ERROR!";

		return ans;
	}
};
