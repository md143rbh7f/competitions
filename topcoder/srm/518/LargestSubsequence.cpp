#include <string>

using namespace std;

struct LargestSubsequence
{
	string getLargest( string s )
	{
		string ans;
		for( int i = s.length()-1; i >= 0; i-- ) if( ans == "" || s[i] >= ans[0] ) ans = s[i] + ans;
		return ans;
	}
};
