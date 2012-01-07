#include <map>
#include <vector>

using namespace std;

double area[55], var[55], mean[55];

struct MagicBlizzard
{
	double expectation( vector<int> range, vector<int> amt )
	{
		map<int,int> rtoa;
		for( int i = 0; i < range.size(); i++ ) rtoa[range[i]] += amt[i];
		int n = rtoa.size();
		map<int,int>::iterator it = rtoa.begin();
		for( int i = 1; i <= n; i++, it++ )
		{
			int width = 2 * ( it->first ) + 1;
			area[i] = width * width;
			mean[i] = ( it->second ) / area[i];
			var[i] = ( it->second ) * ( area[i] - 1 ) / area[i] / area[i];
		}
		double ans = 0, tot_mean = 0, tot_var = 0;
		for( int i = n; i > 0; i-- )
		{
			tot_mean += mean[i];
			tot_var += var[i];
			ans += ( area[i] - area[i-1] ) * ( tot_var + tot_mean * tot_mean );
		}
		return ans;
	}
};
