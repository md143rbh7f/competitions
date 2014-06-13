#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

struct BuildingHeights
{
int minimum(vi hs)
{
	int n = hs.size();
	sort(all(hs));
	vi best(n + 1, 123456789);
	rep(i, n)
	{
		int c = 0;
		rep(j, i + 1) best[j + 1] = min(best[j + 1], c += hs[i] - hs[i - j]);
	}
	int ans = 0;
	rep(i, n) ans ^= best[i + 1];
	return ans;
}
};
