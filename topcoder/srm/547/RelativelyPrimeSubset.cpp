#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

int _p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

struct RelativelyPrimeSubset
{
	int findSize( vector<int> nums )
	{
		bool one = false;
		set<int> p( _p, _p + sizeof(_p) / sizeof(int) ), good;
		foreach( i, nums )
		{
			if( *i == 1 ) one = true;
			else if( p.count( *i ) ) good.insert(*i);
		}

		vector<int> nums2;
		foreach( i, nums )
		{
			bool bad = *i != 1;
			foreach( j, good ) if( *i % *j == 0 ) bad = false;
			if( bad ) nums2.push_back( *i );
		}
		nums = nums2;

		set<int> p2;
		foreach( i, nums ) foreach( j, p ) if( *i % *j == 0 ) p2.insert( *j );
		p = p2;

		set<int> sigs;
		foreach( i, nums )
		{
			int sig = 0, flag = 1;
			foreach( j, p )
			{
				if( *i % *j == 0 ) sig ^= flag;
				flag <<= 1;
			}
			sigs.insert( sig );
		}

		int n = p.size(), m = 1 << n;
		vector<int> dp( m, -1 );
		dp[0] = 0;
		foreach( i, sigs ) for( int j = m - 1 - *i; j >= 0; j-- )
		if( dp[j] != -1 && ( j & *i ) == 0 )
			dp[j|*i] = max( dp[j|*i], 1 + dp[j] );

		int ans = 0;
		foreach( i, dp ) ans = max( ans, *i );
		return one + good.size() + ans;
	}
};
