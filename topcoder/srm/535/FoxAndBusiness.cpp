#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1e11
#define N 55

double q[N], w[N];

struct FoxAndBusiness
{
	double minimumCost( int k, int tw, vector<int> a, vector<int> p )
	{
		int n = a.size();
		for( int i = 0; i < n; i++ ) q[i] = tw * ( (double) a[i] * p[i] + 3600 );
		double ans = MAX;
		for( double d = MAX; d > 0; d /= 2 )
		{
			double c = ans - d, sum = 0;
			for( int i = 0; i < n; i++ ) w[i] = c * a[i] - q[i];
			sort( w, w + n );
			for( int i = 0; i < k; i++ ) sum += w[n-i-1];
			if( sum >= 0 ) ans = c;
		}
		return ans;
	}
};
