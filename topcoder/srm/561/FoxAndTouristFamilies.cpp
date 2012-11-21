#include <vector>

using namespace std;

#define N 55

int d[N][N];

struct FoxAndTouristFamilies
{
	double expectedLength( vector<int> a, vector<int> b, vector<int> f )
	{
		int n = a.size() + 1;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) if( i != j )
			d[i][j] = 9001;
		for( int i = 0; i < n - 1; i++ )
			d[a[i]][b[i]] = d[b[i]][a[i]] = 1;
		for( int k = 0; k < n; k++ )
		for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
		if( d[i][j] > d[i][k] + d[k][j] )
			d[i][j] = d[i][k] + d[k][j];

		double ans = 0;
		for( int i = 0; i < n - 1; i++ )
		{
			double p = 1;
			int u = a[i], v = b[i], cu = 0, cv = 0;
			for( int j = 0; j < n; j++ ) ( d[j][u] < d[j][v] ? cu : cv )++;
			for( int j = 0; j < f.size(); j++ )
				p *= 1.0 * ( d[f[j]][u] < d[f[j]][v] ? cv : cu ) / ( n - 1 );
			ans += p;
		}
		return ans;
	}
};
