#include <algorithm>
#include <vector>

using namespace std;

struct TheProgrammingContestDivTwo
{
	vector<int> find( int T, vector<int> rt )
	{
		int n = rt.size(), t = 0;
		vector<int> ans(2);
		sort(rt.begin(),rt.end());
		for( int i = 0; i < n; i++ ) if( rt[i] + t <= T )
		{
			ans[0]++;
			t += rt[i];
			ans[1] += t;
		}
		return ans;
	}
};
