#include <vector>

using namespace std;

struct SellingProducts
{
	int optimalPrice( vector<int> p, vector<int> c )
	{
		int n = p.size(), maxp = 0, ans = 0;
		for( int i = 0; i < n; i++ )
		{
			int profit = 0;
			for( int j = 0; j < n; j++ ) if(p[j]>=p[i]&&p[i]>=c[j]) profit += p[i]-c[j];
			if(profit>maxp) maxp=profit, ans=p[i];
		}
		return ans;
	}
};
