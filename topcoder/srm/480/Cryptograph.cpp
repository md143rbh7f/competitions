#include <vector>

using namespace std;

struct Cryptography
{
	long long encrypt( vector<int> nums )
	{
		long long ans = 1;
		int min = 1000;
		for( int i = 0; i < nums.size(); i++ ) if(nums[i]<min) min=nums[i];
		for( int i = 0; i < nums.size(); i++ ) ans *= nums[i];
		return ans/min*(min+1);
	}
};
