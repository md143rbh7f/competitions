#include <algorithm>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#define N 50

pair<int,int> l[N], r[N];

struct DengklekMakingChains
{
	int maxBeauty( vector<string> chains )
	{
		int n = chains.size(), whole = 0, mid = 0;
		for( int i = 0; i < n; i++ )
		{
			if( chains[i][0] == '.' && chains[i][1] != '.' && chains[i][2] == '.' ) mid = max( mid, chains[i][1] - '0' );
			else
			{
				bool clean = true;
				for( int j = 0; j < 3; j++ ) if( chains[i][j] == '.' ) clean = false;
				if( clean )
				{
					for( int j = 0; j < 3; j++ ) whole += chains[i][j] - '0';
					chains[i] = "...";
				}
			}
		}
		for( int i = 0; i < n; i++ )
		{
			int left = 0, right = 0;
			for( int j = 0; j < 3 && chains[i][j] != '.'; j++ ) left += chains[i][j] - '0';
			for( int j = 2; j > -1 && chains[i][j] != '.'; j-- ) right += chains[i][j] - '0';
			l[i] = make_pair( left, i );
			r[i] = make_pair( right, i );
		}
		sort(l,l+n);
		sort(r,r+n);
		if( n == 1 )
		{
			 if( whole > 0 ) return whole;
			 if( mid > 0 ) return mid;
			 return max( l[0].first, r[0].first );
		}
		int ans = mid;
		if( l[n-1].second == r[n-1].second ) ans = max( ans, whole + max( l[n-1].first + r[n-2].first, l[n-2].first + r[n-1].first ) );
		else ans = max( ans, whole + l[n-1].first + r[n-1].first );
		return ans;
	}
};
