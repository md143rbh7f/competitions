#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define N 55

int id[N], best[N];
bool g[N][N], ok[N];

struct BigO
{
	int minK(vs e)
	{
		int n = e.size();
		rep(i, n) rep(j, n) g[i][j] = i == j || e[i][j] == 'Y';
		rep(k, n) rep(i, n) rep(j, n) g[i][j] |= g[i][k] && g[k][j];

		int c = 1;
		rep(i, n) if(!id[i])
		{
			int m = 0, k = 0;
			rep(j, n) if(g[i][j] && g[j][i]) id[j] = c, k++;
			rep(j, n) rep(k, n) m += id[j] == c && id[k] == c && e[j][k] == 'Y';
			if(m > k) return -1;
			best[c] = ok[c] = k > 1;
			c++;
		}

		int ans = 0;
		rep(k, n) rep(i, n) rep(j, n) if(g[i][j] && id[i] != id[j])
			acc(max, ans, acc(max, best[id[i]], best[id[j]] + ok[id[i]]));
		return max(0, ans - 1);
	}
};
