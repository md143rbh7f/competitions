#include <algorithm>
#include <vector>

using namespace std;

struct FoxPlusMinus
{
	vector<int> promote( vector<int> & x, int n )
	{
		vector<int> ans = x;
		int m = x.size();
		for( int i = n + 1; i < m; i++ ) ans[i] = x[i-1];
		ans[n] = x[m-1];
		return ans;
	}

	vector<int> maximize( vector<int> x, int n )
	{
		sort( x.begin(), x.end() );
		int m = x.size();
		if( n < m ) return promote( x, n );
		if( m % 2 )
		{
			n %= m + 1;
			if( n != m ) return promote( x, n );
		}
		vector<int> ans(m);
		int j = 0, k = ( m ^ n ) & 1;
		for( int i = 1 - k; i < m; i += 2 ) ans[i] = i < n - m ? x[ m / 2 - i / 2 - 1 ] : x[j++];
		for( int i = k; i < m; i += 2 ) ans[i] = x[ i / 2 + m / 2 ];
		return ans;
	}
};
