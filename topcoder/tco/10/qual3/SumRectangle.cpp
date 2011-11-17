#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int ans[15][15];

class SumRectangle
{
	public:
	int getCorner( vector<int> l, vector<int> t )
	{
		int n = l.size(), m = t.size();
		rep(i,n) ans[i][0] = l[i];
		rep(j,m) ans[0][j] = t[j];
		REP(i,1,n) REP(j,1,m) ans[i][j] = ans[i-1][j-1]-ans[i-1][j]-ans[i][j-1];
		return ans[n-1][m-1];
	}
};
