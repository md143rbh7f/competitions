#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define N (1<<16)

int ans[N];

inline int bit(int i, int j)
{ return (i >= 0 && i < 4 && j >= 0 && j < 4) << (4 * i + j); }

struct SixteenBricks
{
int maximumSurface(vi h)
{
	sort(all(h), greater<int>());
	range(m, 1, N)
	{
		int & c = ans[m] = 123456789, x = h[__builtin_popcount(m) - 1];
		rep(i, 4) rep(j, 4) if(m & bit(i, j))
		{
			int y = bit(i - 1, j) | bit(i + 1, j) | bit(i, j - 1) | bit(i, j + 1);
			c = min(c, 2 * __builtin_popcount(m & y) * x + ans[m ^ bit(i, j)]);
		}
	}
	return 16 + 4 * accumulate(all(h), 0) - ans[N-1];
}
};
