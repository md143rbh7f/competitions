#include <cmath>
#include <vector>

using namespace std;

#define EPS 1e-9

struct FoxProgression
{
	int theCount( vector<int> s )
	{
		int n = s.size();
		if( n==1 ) return -1;
		int arith = 2 * s[1] - s[0], aok = 1;
		for( int i = 2; i < n; i++ )
		{
			if( arith != s[i] ) aok = 0;
			else arith += s[1] - s[0];
		}
		int allzero = aok && arith == 0 && s[0] == 0, geom = 0, gok = allzero;
		if( !allzero && s[0] != 0 && ( s[1] % s[0] ) == 0 )
		{
			geom = s[1] / s[0] * s[1], gok = 1;
			for( int i = 2; i < n; i++ )
			{
				if( geom != s[i] ) gok = 0;
				else geom *= s[1] / s[0];
			}
		}
		return aok + gok - ( aok && gok && arith == geom );
	}
};
