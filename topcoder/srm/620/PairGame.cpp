#include <algorithm>
#include <set>

using namespace std;

typedef pair<int,int> pii;

set<pii> get(int a, int b)
{
	set<pii> ans;
	while(true)
	{
		ans.insert({a, b});
		if(a < b) b -= a;
		else if(b < a) a -= b;
		else break;
	}
	return ans;
}

struct PairGame
{
	int maxSum(int a, int b, int c, int d)
	{
		auto s = get(a, b), t = get(c, d);
		int ans = -1;
		for(auto & p : s) if(t.count(p)) ans = max(ans, p.first + p.second);
		return ans;
	}
};
