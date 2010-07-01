#include <vector>

using namespace std;

class LinearTravellingSalesman
{
	public:
	int findMinimumDistance(vector <int> x, vector <int> y)
	{
		int minx = 100000, miny = 100000, maxx = -1, maxy = -1, n = x.size();
		for( int i = 0; i < n; i++ )
		{
			if( x[i]<minx ) minx = x[i];
			if( x[i]>maxx ) maxx = x[i];
			if( y[i]<miny ) miny = y[i];
			if( y[i]>maxy ) maxy = y[i];
		}
		return maxx+maxy-minx-miny;
	}
};
