#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

struct TheBrickTowerMediumDivOne
{
	vector<int> find( vector<int> h )
	{
		int n = h.size();
		vector<int> ans;
		vector< pair< int, int > > rem;

		int last = h[0];
		ans.push_back(0);
		for( int i = 1; i < n; i++ )
		{
			if( h[i] <= last ) last = h[i], ans.push_back( i );
			else rem.push_back( make_pair( h[i], i ) );
		}

		sort( rem.begin(), rem.end() );
		for( int i = 0; i < rem.size(); i++ ) ans.push_back( rem[i].second );

		return ans;
	}
};
