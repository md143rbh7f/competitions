#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define CLR(i,n) memset(i,n,sizeof(i))
#define clr(i) CLR(i,0)

char buf[10];
int nums[7], n, N, ans, a, b;
set<int> gen[1<<7];

int main()
{
	while(1)
	{
		clr(buf);
		scanf("%s",buf);
		for(n=0;buf[n];n++);
		if(buf[0]=='0'&&n==1) break;
		N=1<<n;
		rep(i,N) if(i)
		{
			gen[i].clear();
			if(!(i&(i-1)))
			{
				rep(j,n) if((i>>j)&1) gen[i].insert(buf[j]-'0');
			}
			else for(int j=(i-1)&i;j;j=(j-1)&i) foreach(x,gen[j]) foreach(y,gen[i-j])
			{
				a=*x,b=*y;
				gen[i].insert(a+b);
				gen[i].insert(a-b);
				gen[i].insert(a*b);
				if(b) gen[i].insert(a/b);
			}
		}
		ans=1;
		while(gen[N-1].find(ans)!=gen[N-1].end()) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
