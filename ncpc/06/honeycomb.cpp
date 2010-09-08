#include <cstring>
#include <cstdio>

using namespace std;

#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define clear(i,n) memset(i,n,sizeof(i))
#define clr(i) clear(i,0)

#define MAX 20

int cases, n, dp[MAX][MAX][2], dx[] = { -1, -1, 0, 1, 1, 0 }, dy[] = { 0, -1, -1, 0, 1, 1 };

int main()
{
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&n);
		clr(dp);
		dp[10][10][n%2] = 1;
		while(n--)
		{
			rep(i,MAX) rep(j,MAX) rep(d,6)
			{
				int tx = i+dx[d], ty = j+dy[d];
				if(tx>=0&&tx<MAX&&ty>=0&&ty<MAX) dp[tx][ty][n%2] += dp[i][j][1-(n%2)];
			}
			rep(i,MAX) rep(j,MAX) dp[i][j][1-(n%2)] = 0;
		}
		printf("%d\n",dp[10][10][0]);
	}
	return 0;
}
