#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <utility>

using namespace std;

set< pair<double,int> > q;
vector<double> e;
bool seen[150];

struct TransportationNetwork
{
	double minCost( vector<int> x, vector<int> y, double rc, double ac )
	{
		int n = x.size();
		for( int j = 0; j < n; j++ ) q.insert( make_pair( hypot( x[0]-x[j], y[0]-y[j] ), j ) );
		seen[0] = true;
		while( !q.empty() )
		{
			double d = q.begin()->first;
			int i = q.begin()->second;
			q.erase(q.begin());
			if( seen[i] ) continue;
			e.push_back(d);
			seen[i] = true;
			for( int j = 0; j < n; j++ ) q.insert( make_pair( hypot( x[i]-x[j], y[i]-y[j] ), j ) );
		}
		sort( e.begin(), e.end() );
		double ans = 1e11, tot = 0;
		for( int i = 0; i < n-1; i++ )
		{
			if( tot + ( n - i ) * ac < ans ) ans = tot + ( n - i ) * ac;
			tot += rc * e[i];
		}
		if( tot < ans ) ans = tot;
		return ans;
	}
};
