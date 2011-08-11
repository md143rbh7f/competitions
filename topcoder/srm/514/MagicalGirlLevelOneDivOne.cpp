#include <string>
#include <vector>

using namespace std;

struct MagicalGirlLevelOneDivOne
{
	string isReachable( vector<int> k, int x, int y )
	{
		for( int i = 0; i < k.size(); i++ ) if( k[i]%2 == 0 ) return "YES";
		if( x < 0 ) x = -x;
		if( y < 0 ) y = -y;
		if( x%2 == y%2 ) return "YES";
		return "NO";
	}
};
