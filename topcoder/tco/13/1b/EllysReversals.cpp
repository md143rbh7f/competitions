#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using namespace std;

string canonical( string s )
{
	int n = s.size();
	vector< pair<char,char> > t;
	for( int i = 0; i + 1 < n; i += 2 )
		t.push_back( make_pair( min( s[i], s[i+1] ), max( s[i], s[i+1] ) ) );
	sort( t.begin(), t.end() );
	string ans;
	for( int i = 0; i < t.size(); i++ )
		ans += t[i].first, ans += t[i].second;
	if( n % 2 ) ans += s[n-1];
	return ans;
}

struct EllysReversals
{
	int getMin( vector<string> strs )
	{
		int n = strs.size(), ans = 0;
		for( int i = 0; i < n; i++ ) strs[i] = canonical( strs[i] );
		sort( strs.begin(), strs.end() );
		for( int i = 0; i < n; )
		{
			if( i + 1 < n && strs[i] == strs[i+1] ) i += 2;
			else ans++, i++;
		}
		return ans;
	}
};
