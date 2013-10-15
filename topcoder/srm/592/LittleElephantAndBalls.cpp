#include <string>

using namespace std;

int ans, l, r;

struct LittleElephantAndBalls
{
	int getNumber(string s)
	{
		for(auto c : s)
		{
			ans += __builtin_popcount(l) + __builtin_popcount(r);
			int x = 1 << (c == 'R' ? 0 : c == 'G' ? 1 : 2);
			(l & x ? r : l) |= x;
		}
		return ans;
	}
};
