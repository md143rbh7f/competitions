#include <cstdlib>
#include <vector>

using namespace std;

int d[16];

struct CrouchingAmoebas
{
	int count( vector<int> X, vector<int> Y, int A, int T )
	{
		int ans = 0, n = X.size();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
		for( int dx = -T; dx <= T; dx++ ) for( int dy = -T; dy <= T; dy++ )
		if( abs(dx) + abs(dy) <= T )
		{
			int x = X[i] + dx, y = Y[j] + dy;
			for( int k = 0; k <= T; k++ ) d[k] = 0;
			for( int k = 0; k < n; k++ )
			{
				int dist = 0;
				if( X[k] < x ) dist += x - X[k];
				if( X[k] > x + A ) dist += X[k] - x - A;
				if( dist > T ) continue;
				if( Y[k] < y ) dist += y - Y[k];
				if( Y[k] > y + A ) dist += Y[k] - y - A;
				if( dist > T ) continue;
				d[dist]++;
			}
			int cnt = d[0], t = T;
			for( int k = 1; k <= t; k++ )
			{
				int can = min( t/k, d[k] );
				t -= can*k;
				cnt += can;
			}
			ans = max( ans, cnt );
		}
		return ans;
	}
};
