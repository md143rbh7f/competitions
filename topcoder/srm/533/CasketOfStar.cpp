#include <vector>

using namespace std;

vector<int> weight;
int mem[55][55];

int rec( int a, int b )
{
	int & ans = mem[a][b];
	if( ans != -1 ) return ans;
	ans = 0;
	if( b - a < 2 ) return ans;
	for( int i = a+1; i < b; i++ )
	{
		int test = rec( a, i ) + rec( i, b );
		if( test > ans ) ans = test;
	}
	ans += weight[a] * weight[b];
	return ans;
}

struct CasketOfStar
{
	int maxEnergy( vector<int> _weight )
	{
		weight = _weight;
		int n = weight.size();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) mem[i][j] = -1;
		return rec( 0, n-1 );
	}
};
