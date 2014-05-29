#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define N 55

int d[N][N];

struct BuildingRoutes
{
	int build(vs dist, int t)
	{
		int n = dist.size();
		rep(i, n) rep(j, n)
			d[i][j] = dist[i][j] - '0';
		rep(k, n) rep(i, n) rep(j, n)
			acc(min, d[i][j], d[i][k] + d[k][j]);
		
		int ans = 0;
		rep(i, n) rep(j, n)
		{
			int cnt = 0, del = dist[i][j] - '0';
			rep(k, n) rep(l, n)
				cnt += d[k][l] == d[k][i] + del + d[j][l];
			if(cnt >= t)
				ans += d[i][j];
		}
		return ans;
	}
};
