#include <vector>

using namespace std;

bool seen[50];

struct CircleMarket
{
	int makePurchases( vector<int> o, vector<int> c, int dt )
	{
		int p = 0, ans = 0;
		for( int t=0; t<=1000000; t+=dt )
		{
			if(t>=o[p]&&t<=c[p]&&!seen[p]) seen[p] = true, ans++;
			p=(p+1)%o.size();
		}
		return ans;
	}
};
