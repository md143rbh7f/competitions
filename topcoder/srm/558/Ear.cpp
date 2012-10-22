#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define N 305

int n, m, rx[N], bx[N], by[N];

int parse( vector<string> & arr, int * ans )
{
	string str = "";
	for( int i = 0; i < arr.size(); i++ ) str += arr[i];
	istringstream iss( str );
	int cur, i = 0;
	while( iss >> cur ) ans[i++] = cur;
	return i;
}

int ways( int px, int py, int qx, int qy, int * rx, int c )
{
	double ax_max = px - ( qx < px ? 1.0 * py * ( px - qx ) / ( py - qy ) : 0 );
	int ax = 0, bx = 0;
	for( int i = 0; i < n; i++ ) ax += c * rx[i] < ax_max, bx += c * rx[i] < qx;
	return ax * ( 2 * bx - ax - 1 ) / 2;
}

struct Ear
{
	ll getCount( vector<string> _rx, vector<string> _bx, vector<string> _by )
	{
		n = parse( _rx, rx ), m = parse( _bx, bx ), parse( _by, by );
		ll ans = 0;
		for( int p = 0; p < m; p++ ) for( int q = 0; q < m; q++ ) if( by[p] > by[q] )
		{
			int l = ways( bx[p], by[p], bx[q], by[q], rx, 1 );
			int r = ways( -bx[p], by[p], -bx[q], by[q], rx, -1 );
			ans += (ll) l * r;
		}
		return ans;
	}
};
