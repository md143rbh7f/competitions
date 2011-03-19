#include <vector>

using namespace std;

bool s[500];

struct SRMCards
{
	int maxTurns( vector<int> srm )
	{
		for( int i = 0; i < srm.size(); i++ ) s[srm[i]] = true;
		int ans = 0;
		for( int i = 0; i < 500; i++ )
		{
			int j = i;
			while( j < 500 && s[j] ) j++;
			ans += (j-i+1)/2;
			i = j;
		}
		return ans;
	}
};
