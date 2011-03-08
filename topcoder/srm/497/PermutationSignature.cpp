#include <string>
#include <vector>

using namespace std;

struct PermutationSignature
{
	vector<int> reconstruct( string s )
	{
		int n = s.size();
		vector<int> ans(n+1);
		for( int i = 0; i <= n; i++ )
		{
			if( s[i]=='D' )
			{
				int j = i;
				while( j < n && s[j]=='D' ) j++;
				for( int k = i; k <= j; k++ ) ans[k] = j-k+i+1;
				i = j;
			}
			else ans[i] = i+1;
		}
		return ans;
	}
};
