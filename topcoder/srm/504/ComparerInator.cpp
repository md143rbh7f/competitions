#include <vector>

using namespace std;

struct ComparerInator
{
	int makeProgram( vector<int> a, vector<int> b, vector<int> c )
	{
		int n = a.size();
		bool eqa = true, eqb = true, lt = true, gt = true;
		for( int i = 0; i < n; i++ )
		{
			if( c[i] != a[i] ) eqa = false;
			if( c[i] != b[i] ) eqb = false;
			if( c[i] != ( a[i]<b[i] ? a[i] : b[i] ) ) lt = false;
			if( c[i] != ( a[i]<b[i] ? b[i] : a[i] ) ) gt = false;
		}
		if( eqa || eqb ) return 1;
		if( lt || gt ) return 7;
		return -1;
	}
};
