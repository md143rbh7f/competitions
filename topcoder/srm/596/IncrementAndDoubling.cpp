#include <vector>

using namespace std;

typedef vector<int> vi;
 
struct IncrementAndDoubling
{
	int getMin(vi xs)
	{
		int len = 0, count = 0;
		for(auto x : xs)
		{
			count += __builtin_popcount(x);
			int i = 0;
			while(x) x >>= 1, i++;
			if(i) i--;
			if(i > len) len = i;
		}
		return count + len;
	}
};
