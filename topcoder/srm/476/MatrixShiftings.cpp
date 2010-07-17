#include <vector>
#include <string>

using namespace std;

struct MatrixShiftings
{
	int minimumShifts( vector<string> M, int v )
	{
		int n = M.size(), m = M[0].size(), best = 1111;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) if( M[i][j]-'0'==v ) best = min( best, min(i,n-i)+min(j,m-j) );
		return best==1111 ? -1 : best;
	}
};
