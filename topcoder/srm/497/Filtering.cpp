#include <string>
#include <vector>

using namespace std;

vector<int> ans;

struct Filtering
{
	vector<int> designFilter( vector<int> s, string ar )
	{
		int a = 101, b = 0, n = s.size();
		for( int i = 0; i < n; i++ ) if( ar[i]=='A' )
		{
			if( s[i]<a ) a = s[i];
			if( s[i]>b ) b = s[i];
		}
		for( int i = 0; i < n; i++ ) if( ar[i]=='R' && s[i]>=a && s[i]<=b ) return ans;
		ans.push_back(a), ans.push_back(b);
		return ans;
	}
};
