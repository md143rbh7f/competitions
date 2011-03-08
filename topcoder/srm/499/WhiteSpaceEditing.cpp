#include <vector>

using namespace std;

struct WhiteSpaceEditing
{
	int getMinimum( vector<int> l )
	{
		int ans = l.size() - 1 + l[0];
		for( int i = 1; i < l.size(); i++ ) if( l[i] > l[i-1] ) ans += l[i] - l[i-1];
		return ans;
	}
};
