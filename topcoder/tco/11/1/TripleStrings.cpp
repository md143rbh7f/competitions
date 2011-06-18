#include <string>

using namespace std;

struct TripleStrings
{
	int getMinimumOperations( string init, string goal )
	{
		int n = init.size();
		for( int i = 0; i < n; i++ )
		{
			bool ok = true;
			for( int j = i; j < n; j++ ) if( init[j] != goal[j-i] ) ok = false;
			if( ok ) return 2 * i;
		}
		return 2 * n;
	}
};
