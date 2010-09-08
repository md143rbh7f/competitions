#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define CLR(i,n) memset(i,n,sizeof(i))
#define clr(i) CLR(i,0)

bool g[40][40];
int n, d, m, dp[2][40][40], x, y, t;
double EPS = 1e-13;
vector<piii> mo;

int main()
{
	while(1)
	{
		scanf("%d%d%d",&n,&d,&m);
		if(!n&&!d&&!m) break;
		mo.clear(), clr(dp);
		rep(i,m) scanf("%d%d%d",&x,&y,&t), mo.push_back(mp(t,mp(x,y)));
		sort(mo.begin(),mo.end());
		int T = 10;
		m--, n += 20;
		while(T--)
		{
			t = T%2;
			clr(g);
			while(m>=0&&mo[m].first>T) g[mo[m].second.first+10][mo[m].second.second+10] = true, m--;
			rep(i,n) rep(j,n) dp[t][i][j] = 0;
			rep(i,n) rep(j,n) REP(dx,-d,d+1) REP(dy,-d,d+1) if(sqrt(dx*dx+dy*dy)<=d+EPS)
			{
				x = i+dx, y = j+dy;
				if(x>=0&&x<n&&y>=0&&y<n)
				{
					int c = 0;
					REP(u,min(i,x),max(i,x)+1) REP(v,min(j,y),max(j,y)+1) if( abs((u-i)*dy-(v-j)*dx)<=EPS && g[u][v] ) c++;
					dp[t][i][j] = max(dp[t][i][j],c+dp[1-t][x][y]);
				}
			}
		}
		int ans = 0;
		rep(i,n) rep(j,n) ans = max(ans,dp[0][i][j]);
		printf("%d\n",ans);
	}
	return 0;
}
