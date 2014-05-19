#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define INF 1234567890

struct BallsSeparating
{
	int minOperations(vi r, vi g, vi b)
	{
		int n = r.size(), ans = INF;
		if(n < 3) return -1;
		rep(i, n) rep(j, n) if(j != i) rep(k, n) if(k != i && k != j)
		{
			int s = g[i] + b[i] + r[j] + b[j] + r[k] + g[k];
			rep(l, n) if(l != i && l != j && l != k)
				s += min(min(r[l] + g[l], r[l] + b[l]), g[l] + b[l]);
			ans = min(ans, s);
		}
		return ans;
	}
};
