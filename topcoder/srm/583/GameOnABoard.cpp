#include <algorithm>
#include <list>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef pair<int,int> pii;
#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define INF 9001
#define N 50

int n, m, d[N][N], dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
vs c;

int work( int x0, int y0 )
{
	list<pii> q;
	rep(i,n) rep(j,m) d[i][j] = INF;
	d[x0][y0] = c[x0][y0] - '0';
	q.push_back( mp( x0, y0 ) );
	while( !q.empty() )
	{
		int x = q.front().first, y = q.front().second;
		q.pop_front();
		rep(dir,4)
		{
			int xx = x + dx[dir], yy = y + dy[dir];
			if( xx < 0 || xx >= n || yy < 0 || yy >= m ) continue;
			bool len = c[xx][yy] - '0';
			int dd = d[x][y] + len;
			if( d[xx][yy] <= dd ) continue;
			d[xx][yy] = dd;
			if( len ) q.push_back( mp( xx, yy ) );
			else q.push_front( mp( xx, yy ) );
		}
	}

	int ans = 0;
	rep(i,n) rep(j,m) acc( max, ans, d[i][j] );
	return ans;
}

struct GameOnABoard
{
	int optimalChoice( vs _c )
	{
		c = _c, n = c.size(), m = c[0].size();
		int ans = INF;
		rep(i,n) rep(j,m) acc( min, ans, work( i, j ) );
		return ans;
	}
};
