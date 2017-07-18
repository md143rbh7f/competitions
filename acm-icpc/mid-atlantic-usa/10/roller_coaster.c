#include <stdio.h>

#define REP(i,a,b) for(i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

#define MAX 20001

int n,k,l,f,d,dp[MAX][2],i,j,t;

int main()
{
	while(1)
	{
		scanf("%d%d%d",&n,&k,&l);
		if(!n) break;
		REP(i,1,MAX) dp[i][0]=l+1;
		rep(i,n)
		{
			t=i%2;
			scanf("%d%d",&f,&d);
			rep(j,MAX)
			{
				dp[j][1-t]=l+1;
				if(dp[j][t]<=l) dp[j][1-t]=min(dp[j][1-t],max(0,dp[j][t]-k));
				if(j>=f) dp[j][1-t]=min(dp[j][1-t],dp[j-f][t]+d);
			}
		}
		j=0;
		rep(i,MAX) if(dp[i][n%2]<=l) j=i;
		printf("%d\n",j);
	}
	return 0;
}
