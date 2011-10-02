#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

long long x[8], y[8], d[8][8];

struct ThreeTeleports
{
	int shortestDistance( int xs, int ys, int xt, int yt, vector<string> tp )
	{
		x[6] = xs, y[6] = ys, x[7] = xt, y[7] = yt;
		for( int i = 0; i < 3; i++ )
		{
			istringstream iss(tp[i]);
			iss >> x[2*i] >> y[2*i] >> x[2*i+1] >> y[2*i+1];
		}
		for( int i = 0; i < 8; i++ ) for( int j = i+1; j < 8; j++ )
			d[i][j] = d[j][i] = abs( x[i] - x[j] ) + abs( y[i] - y[j] );
		for( int i = 0; i < 3; i++ ) if( d[2*i][2*i+1] > 10 )
			d[2*i][2*i+1] = d[2*i+1][2*i] = 10;
		for( int k = 0; k < 8; k++ ) for( int i = 0; i < 8; i++ ) for( int j = 0; j < 8; j++ ) if( d[i][j] > d[i][k] + d[k][j] )
			d[i][j] = d[i][k] + d[k][j];
		return d[6][7];
	}
};
