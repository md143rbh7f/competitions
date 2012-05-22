#include <cmath>
#include <vector>

using namespace std;

int y[55];

struct EllysRivers
{
	double getMin( int Y, int walk, vector<int> X, vector<int> speed )
	{
		int N = X.size();
		double T = 0;
		for( int i = 0; i < N; i++ ) T += 1.0 * X[i] / speed[i];
		for( int i = 0; i < Y; i++ )
		{
			double dT = 1.0 / walk;
			int best = -1;
			for( int j = 0; j < N; j++ )
			{
				double dt = ( hypot( y[j] + 1, X[j] ) - hypot( y[j], X[j] ) ) / speed[j];
				if( dt < dT ) dT = dt, best = j;
			}
			if( best >= 0 ) y[best]++, T += dT;
			else
			{
				T += 1.0 * ( Y - i ) / walk;
				break;
			}
		}
		return T;
	}
};
