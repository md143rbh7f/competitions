#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

double d[100];

struct KingdomXCitiesandVillages
{
	double determineLength( vector<int> cx, vector<int> cy, vector<int> vx, vector<int> vy )
	{
		int n = cx.size(), m = vx.size();
		double ans = 0;
		for( int b = 0; b < m; b++ )
		{
			double minc = 1e11;
			for( int a = 0; a < n; a++ )
			{
				d[a] = hypot( cx[a]-vx[b], cy[a]-vy[b] );
				if( d[a] < minc ) minc = d[a];
			}
			for( int a = 0; a < m; a++ ) d[a+n] = hypot( vx[a]-vx[b], vy[a]-vy[b] );
			sort(d,d+n+m);
			double p = 1;
			for( int a = 1; d[a] < minc; a++ )
			{
				double q = 1.0 / a / ( a + 1 );
				ans += d[a] * q;
				p -= q;
			}
			ans += p * minc;
		}
		return ans;
	}
};
