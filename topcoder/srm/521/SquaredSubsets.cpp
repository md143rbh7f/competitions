#include <set>
#include <vector>

using namespace std;

struct SquaredSubsets
{
	long long countSubsets( int L, vector<int> x, vector<int> y )
	{
		L *= 2;
		vector<int> xx, yy;
		for( int i = 0; i < x.size(); i++ )
		{
			x[i] *= 2;
			xx.push_back( x[i] ), xx.push_back( x[i] - L - 1 );
			y[i] *= 2;
			yy.push_back( y[i] ), yy.push_back( y[i] - L - 1 );
		}
		set<long long> sets;
		for( int i = 0; i < xx.size(); i++ ) for( int j = 0; j < yy.size(); j++ )
		{
			long long mask = 0;
			for( int k = 0; k < x.size(); k++ )
			if( xx[i] <= x[k] && x[k] <= xx[i] + L && yy[j] <= y[k] && y[k] <= yy[j] + L )
				mask |= 1ll << k;
			if(mask) sets.insert(mask);
		}
		return sets.size();
	}
};
