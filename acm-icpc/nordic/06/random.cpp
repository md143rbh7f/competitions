#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAXN 10
#define MAXK 100

int k, n, e, a, b;
vi g[1<<MAXN];
double p[1<<MAXN][2], c[MAXN];

int main()
{
	while(1)
	{
		scanf("%d%d%d",&k,&n,&e);
		if(!k&&!n&&!e) break;
		bool okay = true;
		int N = 1<<n;
		rep(i,N) g[i].clear();
		while(e--) scanf("%d%d",&a,&b), g[a].push_back(b), g[b].push_back(a);
		rep(i,N) p[i][0] = 1.0/N;
		rep(T,k)
		{
			int t = T%2;
			rep(i,n) c[i] = 0;
			rep(i,N) rep(j,n) if((i>>j)&1) c[j] += p[i][t];
			rep(i,n) if(c[i]<=0.25||c[i]>=0.75) okay = false;
			rep(i,N) p[i][1-t] = 0;
			rep(i,N) rep(j,g[i].size()) p[g[i][j]][1-t] += p[i][t]/g[i].size();
		}
		if(okay) printf( "Yes\n" );
		else printf( "No\n" );
	}
	return 0;
}
