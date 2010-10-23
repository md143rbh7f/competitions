#include <string>
#include <vector>

using namespace std;

long long ans;
int a,b,c,d,e,f,g,h,n,m;

struct CubeColoring
{
	long long theCount( vector<string> ok )
	{
		n = ok[0].size();
		for( a = 0; a < n; a++ ) if( ok[0][a]=='Y' )
		for( b = 0; b < n; b++ ) if( ok[2][b]=='Y' )
		for( c = 0; c < n; c++ ) if( ok[5][c]=='Y' )
		for( d = 0; d < n; d++ ) if( ok[7][d]=='Y' )
		{
			e = f = g = h = 0;
			for( m = 0; m < n; m++ )
			{
				if( ok[1][m]=='Y' && m!=a && m!=b && m!=c ) e++;
				if( ok[3][m]=='Y' && m!=a && m!=b && m!=d ) f++;
				if( ok[4][m]=='Y' && m!=a && m!=c && m!=d ) g++;
				if( ok[6][m]=='Y' && m!=b && m!=c && m!=d ) h++;
			}
			ans += e*f*g*h;
		}
		return ans;
	}
};
