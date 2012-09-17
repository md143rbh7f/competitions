#include <vector>
#include <string>

using namespace std;

vector<int> v;
vector<string> g;
int ans;
bool seen[55][1024];

void rec( int i, int j )
{
	if( seen[i][j] ) return;
	if( j > ans ) ans = j;
	seen[i][j] = true;
	for( int k = 0; k < v.size(); k++ ) if( g[i][k] == 'Y' ) rec( k, j ^ v[k] );
}

struct XorTravelingSalesman
{
	int maxProfit( vector<int> _v, vector<string> _g )
	{
		v = _v, g = _g;
		rec( 0, v[0] );
		return ans;
	}
};
