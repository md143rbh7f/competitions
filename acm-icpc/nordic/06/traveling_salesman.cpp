#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstring>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define CLR(i,n) memset(i,n,sizeof(i))
#define clr(i) CLR(i,0)

#define MAX 6000

int c, n, m, tmp, s, t, d[MAX];
map<pair<vi,vi>,vi> e;
set<pii> q;
vi g[MAX];

int main()
{
	while(1)
	{
		scanf("%d",&c);
		if(!c) break;
		e.clear();
		rep(i,c) g[i].clear();
		rep(i,c)
		{
			scanf("%d",&n);
			vector<vi> pts;
			rep(j,n)
			{
				vi pt;
				rep(k,3) scanf("%d",&tmp), pt.push_back(tmp);
				pts.push_back(pt);
			}
			rep(j,n)
			{
				vi a = pts[j], b = pts[(j+1)%n];
				if(a<b) e[mp(a,b)].push_back(i);
				else e[mp(b,a)].push_back(i);
			}
		}
		foreach(i,e)
		{
			vi cs = i->second;
			if(cs.size()==2) g[cs[0]].push_back(cs[1]), g[cs[1]].push_back(cs[0]);
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&s,&t);
			s--, t--;
			CLR(d,MAX), q.clear();
			d[s] = 0, q.insert(mp(0,s));
			while(!q.empty())
			{
				int x = q.begin()->first, v = q.begin()->second;
				q.erase(q.begin());
				if(x==d[v]) foreach(u,g[v]) if(d[v]+1<d[*u])
				{
					d[*u] = d[v]+1;
					q.insert(mp(d[*u],*u));
				}
			}
			printf("%d\n",d[t]);
		}
	}
	return 0;
}
