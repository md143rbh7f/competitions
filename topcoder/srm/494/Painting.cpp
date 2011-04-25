#include <string>
#include <vector>

using namespace std;

bool ok[50][50];

struct Painting
{
	int largestBrush( vector<string> p )
	{
		int n = p.size(), m = p[0].size(), s = 0;
		for( int d = 32; d; d/=2 )
		{
			int t = s+d;
			if( t>n || t>m ) continue;
			for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) ok[i][j] = false;
			for( int i = 0; i+t <= n; i++ ) for( int j = 0; j+t <= m; j++ )
			{
				bool good = true;
				for( int k = 0; k < t; k++ ) for( int l = 0; l < t; l++ ) if( p[i+k][j+l]=='W' ) good = false;
				if(good) for( int k = 0; k < t; k++ ) for( int l = 0; l < t; l++ ) ok[i+k][j+l] = true;
			}
			bool works = true;
			for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) if( p[i][j]=='B' && !ok[i][j] ) works = false;
			if(works) s = t;
		}
		return s;
	}
};
