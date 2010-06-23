#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define MAX 2500

double a[MAX][MAX], EPS = 1e-13;
int num[50][50], dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

class MazeWandering
{
	public:
	double expectedTime( vector<string> maze )
	{
		int n = maze.size(), m = maze[0].size(), N = 0;
		rep(i,n) rep(j,m) num[i][j] = maze[i][j]=='X' ? -1 : N++;
		rep(i,n) rep(j,m)
		{
			int id = num[i][j];
			if( maze[i][j]=='*' ) a[id][id] = 1;
			else if( maze[i][j]=='.' )
			{
				a[id][id] = a[id][N] = 1;
				int c = 0;
				rep(d,4)
				{
					int ii = i+dx[d], jj = j+dy[d];
					if( ii>=0 && jj>=0 && ii<n && jj<m && maze[ii][jj]!='X' ) c++;
				}
				rep(d,4)
				{
					int ii = i+dx[d], jj = j+dy[d];
					if( ii>=0 && jj>=0 && ii<n && jj<m && maze[ii][jj]!='X' ) a[id][num[ii][jj]] = -1.0/c;
				}
			}
		}
		rep(i,N)
		{
			REP(j,i,N)
			if( abs(a[j][i])>=EPS )
			{
				REP(k,i,N+1)
				{
					double t = a[i][k];
					a[i][k] = a[j][k];
					a[j][k] = t;
				}
				break;
			}
			double r = a[i][i];
			REP(k,i,N+1) a[i][k] /= r;
			rep(j,N)
			if( j!=i && abs(a[j][i])>=EPS )
			{
				r = a[j][i];
				REP(k,i,N+1) a[j][k] -= r*a[i][k];
			}
		}
		double ans = 0;
		rep(i,N) ans += a[i][N];
		return ans/N;
	}
};
