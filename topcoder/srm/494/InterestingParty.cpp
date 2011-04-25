#include <map>
#include <string>
#include <vector>

using namespace std;

map<string,int> cnt;

struct InterestingParty
{
	int bestInvitation( vector<string> a, vector<string> b )
	{
		int n = a.size(), best = 0;
		for( int i = 0; i < n; i++ )
		{
			cnt[a[i]]++;
			if(cnt[a[i]]>best) best = cnt[a[i]];
			cnt[b[i]]++;
			if(cnt[b[i]]>best) best = cnt[b[i]];
		}
		return best;
	}
};
