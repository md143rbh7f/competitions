#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define clear(i,n) memset(i,n,sizeof(i))

int cases, n, kills[13][13], next[13][13], l[13];
double dp[1<<13][13][13], p[13], best[13], a[13][14], EPS = 1e-13;
// mask, turn, prob

int main()
{
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&n);
		clear(dp,0), clear(p,0);
		rep(i,n) scanf("%lf",&p[i]), p[i]/=100, dp[1<<i][i][i] = 1;
		REP(m,1,1<<n)
		{
			int c = 0;
			rep(i,n) if(m&(1<<i)) c++;
			if(c>=2)
			{
				clear(best,0), clear(kills,0), clear(next,0), clear(l,0);
				rep(i,n) if(m&(1<<i))
				rep(j,n) if(m&(1<<j))
				if(i!=j)
				{
					int nxt = (i+1)%n;
					while(1)
					{
						if(nxt!=j&&(m&(1<<nxt))) break;
						nxt=(nxt+1)%n;
					}
					if(abs(p[i]*dp[m-(1<<j)][nxt][i]-best[i])<=EPS) kills[i][l[i]] = j, next[i][l[i]] = nxt, l[i]++;
					else if(p[i]*dp[m-(1<<j)][nxt][i]-best[i]>EPS) best[i] = p[i]*dp[m-(1<<j)][nxt][i], kills[i][0] = j, next[i][0] = nxt, l[i] = 1;
				}
				rep(x,n) if(m&(1<<x))
				{
					clear(a,0);
					int q = 0;
					rep(i,n) if(m&(1<<i))
					{
						a[q][q] = 1, a[q][(q+1)%c] = p[i]-1;
						rep(j,l[i]) a[q][c] += dp[m-(1<<kills[i][j])][next[i][j]][x];
						a[q][c] *= p[i]/l[i];
						q++;
					}
					rep(i,c)
					{
						REP(j,i,c)
						if( abs(a[j][i])>=EPS )
						{
							REP(k,i,c+1)
							{
								double t = a[i][k];
								a[i][k] = a[j][k];
								a[j][k] = t;
							}
							break;
						}
						double r = a[i][i];
						REP(k,i,c+1) a[i][k] /= r;
						rep(j,c)
						if( j!=i && abs(a[j][i])>=EPS )
						{
							r = a[j][i];
							REP(k,i,c+1) a[j][k] -= r*a[i][k];
						}
					}
					q = 0;
					rep(i,n) if(m&(1<<i)) dp[m][i][x] = a[q][c], q++;
				}
			}
		}
		rep(i,n) printf("%0.2f ",100*dp[(1<<n)-1][0][i]);
		printf("\n");
	}
	return 0;
}
