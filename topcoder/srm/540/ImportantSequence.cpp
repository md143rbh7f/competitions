#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define INF 1ll<<42

struct ImportantSequence
{
	int getCount(vi x, string s)
	{
		ll lo = 0, hi = INF, m = 1, b = 0;
		rep(i, x.size())
		{
			if(s[i] == '+') m *= -1, b = x[i] - b;
			else b -= x[i];
			if(m == 1) lo = max(lo, -b);
			else hi = min(hi, b);
		}
		return hi == INF ? -1 : max(0ll, hi - lo - 1);
	}
};
