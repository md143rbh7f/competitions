#include <vector>
#include <string>

using namespace std;

typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

vs ans, c, d;
char t[2][2];

struct TwistedMatrix
{
	vs solve( vs a, vs b )
	{
		int n = a.size(), m = a[0].size();
		rep(i,n) c.push_back(string(a[i])), d.push_back(string(a[i]));
		rep(x,n-1) rep(y,m-1) rep(r,4)
		{
			bool okay = r%2;
			rep(i,n) rep(j,m)
			{
				if(b[i][j]!='?'&&c[i][j]!='?'&&b[i][j]!=c[i][j]) okay = false;
				if(b[i][j]!='?') d[i][j] = b[i][j];
				if(c[i][j]!='?') d[i][j] = c[i][j];
				if(b[i][j]=='?'&&c[i][j]=='?') d[i][j] = '0';
			}
			if(okay&&(ans.empty()||d<ans)) ans = d;
			t[0][0] = c[x][y], t[0][1] = c[x][y+1], t[1][1] = c[x+1][y+1], t[1][0] = c[x+1][y];
			c[x][y] = t[0][1], c[x][y+1] = t[1][1], c[x+1][y+1] = t[1][0], c[x+1][y] = t[0][0];
		}
		return ans;
	}
};
