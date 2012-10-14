#include <algorithm>
#include <string>

using namespace std;

struct FoxAndMountainEasy
{
	string possible( int n, int h0, int h1, string hist )
	{
		if( ( h0 ^ h1 ^ n ) & 1 ) return "NO";
		int m = hist.size(), hu = 0, hd = 0, lo = 0;
		for( int i = 0; i < m; i++ ) ( hist[i] == 'U' ? hu : hd )++, lo = min( hu - hd, lo );
		int u = ( n + h1 - h0 ) / 2 - hu, d = ( n - h1 + h0 ) / 2 - hd;
		if( u < 0 || d < 0 || h0 + u + lo < 0 || h1 + d - hu + hd + lo < 0 ) return "NO";
		return "YES";
	}
};
