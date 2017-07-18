#include <cstring>
#include <cstdio>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define irep(i,n) REP(i,1,n+1)
#define clear(i,n) memset(i,n,sizeof(i))
#define clr(i) clear(i,0)

int cases, n, ans[14];

int main()
{
	scanf( "%d", &cases );
	while(cases--)
	{
		scanf( "%d", &n );
		clr(ans);
		int pos = 0;
		irep(i,n)
		{
			int d = 0;
			while(d<i)
			{
				if(!ans[pos]) d++;
				pos = (pos+1)%n;
			}
			while(ans[pos]) pos = (pos+1)%n;
			ans[pos] = i;
		}
		rep(i,n) printf( "%d ", ans[i] );
		printf( "\n" );
	}
	return 0;
}
