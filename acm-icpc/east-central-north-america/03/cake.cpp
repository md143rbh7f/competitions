#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

#define S 8

int T;
double x[S], y[S], EPS = 1e-13;

double area( vector<double> X, vector<double> Y )
{
	int n = X.size();
	double a = 0;
	for( int i = 0; i < n; i++ ) a += X[i%n] * Y[(i+1)%n] - X[(i+1)%n] * Y[i%n];
	a /= 2;
	if( a < 0 ) a = -a;
	return a;
}

int main()
{
	while(1)
	{
		scanf( "%lf%lf%lf%lf%lf%lf%lf%lf", &x[0], &y[0], &x[2], &y[2], &x[4], &y[4], &x[6], &y[6] );
		if( !x[0] && !y[0] && !x[2] && !y[2] && !x[4] && !y[4] && !x[6] && !y[6] ) break;
		for( int i = 1; i < S; i += 2 ) x[i] = ( x[(i+7)%S] + x[(i+1)%S] ) / 2, y[i] = ( y[(i+7)%S] + y[(i+1)%S] ) / 2;
		double a1 = 0, a2 = 1e11;
		for( int i = 0; i < S; i++ ) for( int j = i+2; j < S; j++ )
		{
			vector<double> X1, Y1, X2, Y2;
			for( int k = i; k != (j+1)%S; k = (k+1)%S ) X1.push_back( x[k] ), Y1.push_back( y[k] );
			for( int k = j; k != (i+1)%S; k = (k+1)%S ) X2.push_back( x[k] ), Y2.push_back( y[k] );
			double b1 = area( X1, Y1 ), b2 = area( X2, Y2 );
			if( b1 > b2 )
			{
				double tmp = b1;
				b1 = b2;
				b2 = tmp;
			}
			if( b1 > EPS && b2 > EPS && b2 - b1 < a2 - a1 ) a1 = b1, a2 = b2;
		}
		printf( "Cake %d: %.3lf %.3lf\n", ++T, a1, a2 );
	}
	return 0;
}
