#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

struct PiecewiseLinearFunctionDiv2
{
	vi countSolutions(vi ys, vi qs)
	{
		int n = ys.size();
		vi ans;
		for(auto q : qs)
		{
			int cnt = 0;
			rep(i, n)
			{
				cnt += ys[i] == q;
				if(i)
				{
					cnt += (ys[i - 1] < q && q < ys[i]) || (ys[i - 1] > q && q > ys[i]);
					if(ys[i - 1] == q && ys[i] == q)
					{
						cnt = -1;
						break;
					}
				}
			}
			ans.push_back(cnt);
		}
		return ans;
	}
};
