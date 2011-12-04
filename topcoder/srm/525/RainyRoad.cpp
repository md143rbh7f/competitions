#include <string>
#include <vector>

using namespace std;

struct RainyRoad
{
	string isReachable( vector<string> road )
	{
		for( int i = 1; i < road[0].size(); i++ ) if( road[0][i] == 'W' && road[1][i] == 'W' ) return "NO";
		return "YES";
	}
};
