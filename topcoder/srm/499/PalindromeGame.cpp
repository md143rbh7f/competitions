#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

map< string, vector<int> > m;

struct PalindromeGame
{
	int getMaximum( vector<string> s, vector <int> v )
	{
		int ans = 0, bestm = 0, n = s.size(), p = s[0].size();
		for( int i = 0; i < n; i++ ) m[s[i]].push_back( v[i] );
		foreach( i, m ) sort( i->second.begin(), i->second.end() ), reverse( i->second.begin(), i->second.end() );
		foreach( i, m ) foreach( j, m )
		{
			bool ok = 1;
			for( int k = 0; k < p; k++ ) if( i->first[k] != j->first[p-k-1] ) ok = 0;
			if( !ok ) continue;
			if( i == j )
			{
				int l = i->second.size();
				for( int k = 0; k < l - (l%2); k++ ) ans += i->second[k];
				if( l%2 && i->second[l-1] > bestm ) bestm = i->second[l-1];
			}
			else if( i->first < j->first ) for( int k = 0; k < i->second.size() && k < j->second.size(); k++ ) ans += i->second[k] + j->second[k];
		}
		return ans + bestm;
	}
};
