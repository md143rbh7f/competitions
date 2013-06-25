#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define N 55

int d[N][N];

struct TravelOnMars
{
	int minTimes( vi r, int x0, int x1 )
	{
		int n = r.size();
		rep(i,n) rep(j,n) d[i][j] = N;
		rep(i,n) rep(j,r[i]+1) d[i][(i+j)%n] = d[i][(i-j+n)%n] = 1;
		rep(k,n) rep(i,n) rep(j,n) acc( min, d[i][j], d[i][k] + d[k][j] );
		return d[x0][x1];
	}
};
