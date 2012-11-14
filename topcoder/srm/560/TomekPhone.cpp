#include <algorithm>
#include <vector>

using namespace std;

struct TomekPhone
{
	int minKeystrokes( vector<int> freq, vector<int> sz )
	{
		vector<int> c;
		for( int i = 0; i < sz.size(); i++ ) for( int j = 1; j <= sz[i]; j++ ) c.push_back( j );
		if( c.size() < freq.size() ) return -1;
		sort( c.begin(), c.end() );
		sort( freq.begin(), freq.end() );
		int ans = 0;
		for( int i = 0; i < freq.size(); i++ ) ans += freq[freq.size()-i-1] * c[i];
		return ans;
	}
};
