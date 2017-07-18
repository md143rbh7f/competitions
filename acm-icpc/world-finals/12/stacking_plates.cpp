#include <iostream>
#include <map>
#include <set>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

bool run( int t )
{
	int n;
	cin >> n;
	if( cin.eof() ) return false;

	map< int, set<int> > have;
	for( int i = 0; i < n; i++ )
	{
		int h;
		cin >> h;
		while( h-- )
		{
			int j;
			cin >> j;
			have[-j].insert( i );
		}
	}

	set<int> * prev = NULL;
	map<int,int> best;
	foreach( it, have )
	{
		map<int,int> cur;
		set<int> & s = it->second;
		if( !prev ) foreach( i, s ) cur[*i] = s.size();
		else foreach( i, s )
		{
			int & ans = cur[*i] = -1;
			foreach( j, *prev )
			{
				int test = best[*j] + s.size();
				if( s.count(*j) && ( (*i) != (*j) || ( s.size() == 1 ) ) )
					test--;
				if( ans == -1 || test < ans ) ans = test;
			}
		}
		prev = &s, best = cur;
	}

	int ans = -1;
	foreach( it, best )
	if( ans == -1 || it->second < ans )
		ans = it->second;
	ans = 2 * ans - n - 1;
	cout << "Case " << t << ": " << ans << endl;

	return true;
}

int main()
{
	for( int t = 1; run(t); t++ );
	return 0;
}
