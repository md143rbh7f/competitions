#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

bool a[50][50], top[50];

struct CarrotBoxes
{
	double theProbability( vector<string> g )
	{
		int n = g.size(), best = n;
		rep(i,n) rep(j,n) a[i][j] = g[i][j] == 'Y';
		rep(j,n) rep(i,n) rep(k,n) a[i][k] |= a[i][j] && a[j][k];
		rep(last,n)
		{
			int cnt = 0;
			rep(i,n) top[i] = false;
			rep(i,n) if(i!=last)
			{
				if(top[i]) continue;
				bool ok = true;
				rep(j,n) if( j!=last && a[j][i] && !a[i][j] ) ok = false;
				if(!ok) continue;
				cnt++;
				rep(j,n) if( j!=last && a[i][j] && a[i][j] ) top[j] = true;
			}
			if(cnt<best) best = cnt;
		}
		return 1.0*(n-best)/n;
	}
};
