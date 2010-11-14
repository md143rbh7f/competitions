#include <algorithm>
#include <cstdio>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 1000

int n,a,b,ans,tot,sum,k[MAX],da[MAX],db[MAX],p[MAX],A;

bool lthan(int x,int y)
{
	if(da[x]-db[x]<da[y]-db[y]) return true;
	if(da[x]-db[x]>da[y]-db[y]) return false;
	return x<y;
}

int main()
{
	while(1)
	{
		scanf("%d%d%d",&n,&a,&b);
		if(!n) break;
		ans=1<<30,tot=0;
		rep(i,n) scanf("%d%d%d",&k[i],&da[i],&db[i]), p[i]=i, tot+=k[i];
		sort(p,p+n,lthan);
		REP(i,max(0,tot-b),a+1)
		{
			A=i,sum=0;
			rep(j,n)
			{
				if(A>k[p[j]]) sum+=k[p[j]]*da[p[j]], A-=k[p[j]];
				else sum+=A*da[p[j]]+(k[p[j]]-A)*db[p[j]], A=0;
			}
			ans=min(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
