#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define R 2200

int best[55][R+1];

struct TypoCoderDiv1
{
	int getmax(vi d, int r0)
	{
		int T = d.size();
		best[0][r0] = 1;
		rep(t, T) rep(r, R) if(best[t][r])
		{
			if(r + d[t] >= R)
			{
				acc(max, best[t+1][R], best[t][r] + 1);
				if(t + 1 < T && r + d[t] - d[t + 1] < R)
					acc(max, best[t+2][max(0, r + d[t] - d[t + 1])], best[t][r] + 2);
			}
			else acc(max, best[t+1][r + d[t]], best[t][r]);
			acc(max, best[t+1][max(0, r - d[t])], best[t][r]);
		}

		int ans = 0;
		rep(r, R + 1) acc(max, ans, best[T][r]);
		return ans - 1;
	}
};
