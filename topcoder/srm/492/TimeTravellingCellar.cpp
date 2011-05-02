#include <vector>

using namespace std;

struct TimeTravellingCellar
{
	int determineProfit( vector<int> a, vector<int> b )
	{
		int n = a.size(), best = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) if( j != i && a[i]-b[j] > best ) best = a[i]-b[j];
		return best;
	}
};
