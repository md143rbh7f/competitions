#include <cmath>
#include <set>
#include <utility>
#include <vector>

using namespace std;

set< pair<double,int> > q;
bool seen[50];

struct KingdomXCitiesandVillagesAnother
{
	double determineLength( vector<int> cx, vector<int> cy, vector<int> vx, vector<int> vy )
	{
		int n = cx.size(), m = vx.size();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) q.insert( make_pair( hypot( cx[i]-vx[j], cy[i]-vy[j] ), j ) );
		double ans = 0;
		while( !q.empty() )
		{
			pair<double,int> e = *q.begin();
			q.erase(q.begin());
			int i = e.second;
			if( seen[i] ) continue;
			ans += e.first;
			seen[i] = true;
			for( int j = 0; j < m; j++ ) q.insert( make_pair( hypot( vx[i]-vx[j], vy[i]-vy[j] ), j ) );
		}
		return ans;
	}
};
