#include <string>
#include <vector>

using namespace std;

struct StrangeDictionary
{
	vector<double> getExpectedPositions( vector<string> strs )
	{
		int n = strs.size(), m = strs[0].size();
		vector<double> ans(n);
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) if( i != j )
		{
			int tot = 0, bad = 0;
			for( int k = 0; k < m; k++ )
			{
				tot += strs[i][k] != strs[j][k];
				bad += strs[i][k] > strs[j][k];
			}
			ans[i] += 1.0 * bad / tot;
		}
		return ans;
	}
};
