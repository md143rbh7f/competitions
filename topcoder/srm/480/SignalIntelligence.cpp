#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

struct SignalIntelligence
{
	ll encrypt( vi nums )
	{
		ll ans = 1ll<<63;
		int n = nums.size();
		sort(nums.begin(),nums.end());
		rep(i,n)
		{
			ll l = 1;
			rep(j,n) if(i!=j)
			{
				ll m = l;
				while(nums>m-l-1) m <<= 1;
				l = m;
			}
			l += nums[i];
			if(l<ans) ans = l;
		}
		return ans;
	}
};
