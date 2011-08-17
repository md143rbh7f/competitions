#include <vector>

using namespace std;

int MOD = 1000000009;

struct YetAnotherIncredibleMachine
{
	int countWays( vector<int> mount, vector<int> len, vector<int> balls )
	{
		long long ans = 1;
		for( int i = 0; i < mount.size(); i++ )
		{
			int l = mount[i] - len[i] - 1, r = mount[i] + len[i] + 1;
			for( int j = 0; j < balls.size(); j++ )
			{
				if( balls[j] <= mount[i] && balls[j] > l ) l = balls[j];
				if( balls[j] >= mount[i] && balls[j] < r ) r = balls[j];
			}
			if( r - l > len[i] + 1 ) ans = ( ans * ( r - l - len[i] - 1 ) ) % MOD;
			else return 0;
		}
		return ans;
	}
};
