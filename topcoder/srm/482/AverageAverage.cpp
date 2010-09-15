#include <vector>

using namespace std;

struct AverageAverage
{
	double average( vector<int> nums )
	{
		int n=nums.size();
		double ans=0;
		for(int m=1;m<1<<n;m++)
		{
			double ans2=0;
			int cnt=0;
			for(int i=0;i<n;i++) if((m>>i)&1) cnt++, ans2 += nums[i];
			ans += ans2/cnt;
		}
		return ans/((1<<n)-1);
	}
};
