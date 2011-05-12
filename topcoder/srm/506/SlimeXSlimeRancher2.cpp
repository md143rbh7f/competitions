#include <vector>

using namespace std;

struct SlimeXSlimeRancher2
{
	int train( vector<int> attrs )
	{
		int n = attrs.size(), top = 0, ans = 0;
		for( int i = 0; i < n; i++ ) if( attrs[i] > top ) top = attrs[i];
		for( int i = 0; i < n; i++ ) ans += top - attrs[i];
		return ans;
	}
};
