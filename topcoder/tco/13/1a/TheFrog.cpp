#include <algorithm>
#include <vector>

using namespace std;

struct TheFrog
{
	double getMinimum( int d, vector<int> l, vector<int> r )
	{
		vector< pair<double,double> > a;
		for( int i = 0; i < l.size(); i++ ) for( double j = 1; j <= r[i]; j++ )
			a.push_back( make_pair( l[i] / j, r[i] / j ) );
		double ans = 1;
		sort( a.begin(), a.end() );
		for( int i = 0; i < a.size(); i++ )
		if( a[i].first < ans && ans < a[i].second )
			ans = a[i].second;
		return ans;
	}
};
