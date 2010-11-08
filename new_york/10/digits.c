#include <stdio.h>

#define MAX 65

int n,a,l,i,j;
long long dp[MAX][10],tot[MAX];

int main()
{
	dp[0][0]=1;
	for(l=1;l<MAX;l++) for(j=0;j<10;j++) for(i=0;i<=j;i++) dp[l][j]+=dp[l-1][i];
	for(l=1;l<MAX;l++) for(j=0;j<10;j++) tot[l]+=dp[l][j];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&i,&j);
		printf("%d %lld\n",i,tot[j]);
	}
	return 0;
}
