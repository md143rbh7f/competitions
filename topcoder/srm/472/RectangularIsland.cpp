#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define MAX 1010
#define MAXT 5010

double xs[2][MAXT], tmp[2][MAX], xw[MAXT], yw[MAXT];
int T;

void sim( int n, int x0, double res[] )
{
	rep(i,2) rep(j,MAX) tmp[i][j] = 0;
	tmp[0][x0+1] = res[0] = 1;
	rep(tt,T)
	{
		int t = tt%2;
		rep(i,n+1)
		{
			if( i>=1 && i<=n )
			{
				tmp[1-t][i-1] += tmp[t][i]/2;
				tmp[1-t][i+1] += tmp[t][i]/2;
			}
			tmp[t][i] = 0;
		}
		rep(i,n) res[tt+1] += tmp[1-t][i+1];
	}
}

class RectangularIsland
{
	public:
	double theProbablity( int X, int Y, int x, int y, int _T )
	{
		T = _T;
		xs[0][0] = 1;
		rep(tt,T)
		{
			int t = tt%2;
			rep(i,tt+1)
			{
				xs[1-t][i] += xs[t][i]/2;
				xs[1-t][i+1] += xs[t][i]/2;
				xs[t][i] = 0;
			}
		}
		sim( X, x, xw );
		sim( Y, y, yw );
		double ans = 0;
		rep(t,T+1) ans += xs[T%2][t]*xw[t]*yw[T-t];
		return ans;
	}
};
