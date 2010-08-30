#include <cmath>
#include <vector>

using namespace std;

struct MountainRoad
{
	double findDistance( vector<int> start, vector<int> finish )
	{
		int a = 1000, b = -1000, n = start.size();
		for( int i = 0; i < n; i++ ) a = min(a,start[i]), b = max(b,finish[i]);
		return sqrt(2)*(b-a);
	}
};
