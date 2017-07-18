#include <stdio.h>

typedef long long ll;
#define REP(i,a,b) for(i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 63

int x,i,j,k,K[MAX];
ll a,b,ca[MAX],cb[MAX],ans,ncr[MAX][MAX];

void cnt(ll n,ll* c)
{
	rep(i,MAX) c[i]=0;
	int prev=0;
	for(i=MAX;i>=0;i--) if((n>>i)&1)
	{
		rep(j,MAX-prev) c[j+prev]+=ncr[i][j];
		prev++;
	}
}

int main()
{
	rep(i,MAX) for(j=i;j>1;j=__builtin_popcount(j)) K[i]++;
	rep(i,MAX) ncr[i][0]=1;
	REP(i,1,MAX) REP(j,1,MAX) ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
	printf("\n");
	while(1)
	{
		scanf("%lld%lld%d",&a,&b,&x);
		if(!a) break;
		cnt(a,ca), cnt(b+1,cb);
		ans=0;
		if(x==0)
		{
			if(a<=1&&1<=b) ans=1;
		}
		else if(x==1)
		{
			ans=cb[1]-ca[1];
			// correct for 1
			if(ca[1]) ans++;
			if(cb[1]) ans--;
		}
		else REP(i,2,MAX) if(K[i]+1==x) ans+=cb[i]-ca[i];
		printf("%lld\n",ans);
	}
	return 0;
}
