#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define bit(x,i) ((x>>i)&1)
#define next(i) ((i+1)%n)
#define prev(i) ((i+n-1)%n)

#define N 18

ll ans[1<<N][N];

struct PolygonTraversal
{
	ll count(int n, vi ps)
	{
		int start = 0;
		for(auto & p : ps) start ^= 1 << (p -= 1);
		ans[start][ps.back()] = 1;

		for(int m = start; m < 1<<n; m = (m + 1) | start) rep(i, n)
		{
			int j0 = i, j1 = i;
			do j0 = next(j0); while(!bit(m, j0));
			do j1 = prev(j1); while(!bit(m, j1));
			for(int j = j0; j != j1; j = next(j)) if(!bit(m, j))
				ans[m ^ (1 << j)][j] += ans[m][i];
		}

		ll tot = 0;
		rep(i, n) if(i != next(ps[0]) && i != prev(ps[0]))
			tot += ans[(1<<n)-1][i];
		return tot;
	}
};
