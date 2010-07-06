#include <string>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

// time, index, from
int p[2][17][2];

struct RabbitStepping
{
	double getExpected( string f, int r )
	{
		int n = f.size(), works = 0, sum = 0;
		rep(m,1<<n)
		{
			int cnt = 0, T = n;
			rep(i,n) if( (m>>i)&1 ) cnt++;
			if( cnt!=r ) continue;
			rep(t,2) rep(i,n) rep(j,2) p[t][i][j] = 0;
			rep(i,n) if( (m>>i)&1 ) p[n%2][i][0] = 1;
			while( T>2 )
			{
				int t = T%2;
				rep(i,T)
				{
					if( i==0 ) p[1-t][i+1][0] += p[t][i][0]+p[t][i][1];
					else if( i==T-2 || i==T-1 ) p[1-t][i-1][1] += p[t][i][0]+p[t][i][1];
					else switch(f[i])
					{
						case 'W': p[1-t][i-1][1] += p[t][i][0]+p[t][i][1]; break;
						case 'B': p[1-t][i+1][0] += p[t][i][0]+p[t][i][1]; break;
						case 'R': p[1-t][i-1][1] += p[t][i][0]; p[1-t][i+1][0] += p[t][i][1]; break;
					}
					p[t][i][0] = p[t][i][1] = 0;
				}
				rep(i,T) if( p[1-t][i][0]+p[1-t][i][1]>1 ) p[1-t][i][0] = p[1-t][i][1] = 0;
				T--;
			}
			rep(i,2) rep(j,2) sum += p[0][i][j];
			works++;
		}
		return 1.0*sum/works;
	}
};
