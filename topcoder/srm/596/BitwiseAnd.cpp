#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define B 60
 
int cnt[B];
 
struct BitwiseAnd
{
	vll lexSmallest(vll s, int n)
	{
		for(auto x : s) for(auto y : s) if(!(x&y)) return {};
		rep(b, B)
		{
			for(auto x : s) cnt[b] += 1&(x>>b);
			if(cnt[b] > 2) return {};
		}
		range(i, s.size(), n)
		{
			ll y = 0;
			for(auto x : s)
			{
				bool found = false;
				rep(b, B) if(cnt[b] == 1 && (1&(x>>b)))
				{
					y |= 1ll<<b, cnt[b]++, found = true;
					break;
				}
				if(!found) return {};
			}
			int extra = n - i - 1;
			for(int b = 0; b < B && extra; b++) if(!cnt[b])
				y |= 1ll<<b, cnt[b]++, extra--;
			if(extra) return {};
			s.push_back(y);
		}
		sort(s.begin(), s.end());
		return s;
	}
};
