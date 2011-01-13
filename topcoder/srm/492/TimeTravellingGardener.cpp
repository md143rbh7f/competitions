#include <vector>

using namespace std;

int x[50];

struct TimeTravellingGardener
{
	int determineUsage( vector<int> d, vector <int> h )
	{
		int n = h.size(), best = n-1;
		for( int i = 1; i < n; i++ ) x[i] = x[i-1] + d[i-1];
		for( int i = 0; i < n; i++ ) for( int j = i+1; j < n; j++ )
		{
			int bad = 0;
			for( int k = 0; k < n; k++ ) if( k!=i )
			{
				int a = (h[k]-h[i])*(x[j]-x[i]);
				int b = (h[j]-h[i])*(x[k]-x[i]);
				int want = b + h[i]*(x[j]-x[i]);
				if( want < 0 ) bad = n-1;
				if( a < b ) bad = n-1;
				if( a > b ) bad++;
			}
			if( bad < best ) best = bad;
		}
		return best;
	}
};
