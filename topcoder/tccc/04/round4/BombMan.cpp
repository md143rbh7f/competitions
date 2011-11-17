#include <vector>
#include <set>
#include <string>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define CLR(i,n) memset(i,n,sizeof(i))

set<vi> q;
int d[55][55][111], OVER_NINE_THOUSAND=9001, dx[]={-1,1,0,0}, dy[]={0,0,-1,1}, n, m, sx, sy, ex, ey;

vi state( int dist, int x, int y, int b )
{
	vi res(4);
	res[0]=dist, res[1]=x, res[2]=y, res[3]=b;
	return res;
}

struct BombMan
{
	int shortestPath( vs g, int B )
	{
		CLR(d,OVER_NINE_THOUSAND);
		n=g.size(), m=g[0].size();
		rep(i,n) rep(j,m) if(g[i][j]=='B') sx=i, sy=j;
		rep(i,n) rep(j,m) if(g[i][j]=='E') ex=i, ey=j;
		d[sx][sy][0]=0;
		q.insert(state(0,sx,sy,0));
		while(!q.empty())
		{
			vi v=*q.begin();
			q.erase(q.begin());
			int dist=v[0], x=v[1], y=v[2], b=v[3];
			rep(dir,4)
			{
				int tdist=dist+1, tx=x+dx[dir], ty=y+dy[dir], tb=b;
				if(tx<0||tx>=n||ty<0||ty>=m) continue;
				if(g[tx][ty]=='#') tdist+=2, tb++;
				if(tb>B) continue;
				if(tdist<d[tx][ty][tb]) d[tx][ty][tb]=tdist, q.insert(state(tdist,tx,ty,tb));
			}
		}
		int best=OVER_NINE_THOUSAND;
		rep(i,B+1) best=min(best,d[ex][ey][i]);
		if(best==OVER_NINE_THOUSAND) return -1;
		return best;
	}
};
