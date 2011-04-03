#include <set>
#include <string>
#include <vector>

using namespace std;

set< vector<int> > ans;

struct AnagramFree
{
	int getMaximumSubset( vector<string> s )
	{
		for( int i = 0; i < s.size(); i++ )
		{
			vector<int> cnt(26);
			for( int j = 0; j < s[i].size(); j++ ) cnt[s[i][j]-'a']++;
			ans.insert(cnt);
		}
		return ans.size();
	}
};
