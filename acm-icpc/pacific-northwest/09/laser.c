#include <stdio.h>

#define rep(i,n) for(i=0;i<n;i++)

int n,t,g[20][20],h[20][20],i,j;

void flush()
{
	rep(i,n) rep(j,n) if(h[i][j]) printf("%3d",j), h[i][j]=0;
	printf("\n");
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		rep(i,n) rep(j,n) g[i][j]=h[i][j]=0;
		rep(i,n) scanf("%d",&t), g[i][t]=h[i][t]=1;
		flush();
		rep(i,n) rep(j,n) h[j][n-1-i]=g[i][j];
		flush();
		rep(i,n) rep(j,n) h[n-1-i][n-1-j]=g[i][j];
		flush();
		rep(i,n) rep(j,n) h[n-1-j][i]=g[i][j];
		flush();
		rep(i,n) rep(j,n) h[i][n-1-j]=g[i][j];;
		flush();
		rep(i,n) rep(j,n) h[n-1-j][n-1-i]=g[i][j];;
		flush();
		rep(i,n) rep(j,n) h[n-1-i][j]=g[i][j];;
		flush();
		rep(i,n) rep(j,n) h[j][i]=g[i][j];;
		flush();
		printf("\n");
	}
	return 0;
}
