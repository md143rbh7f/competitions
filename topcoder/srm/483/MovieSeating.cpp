#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<string> vs;
#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

ll c[51][51];

struct MovieSeating
{
	ll getSeatings( int num, vs hall )
	{
		rep(i,51) c[i][0] = 1;
		REP(i,1,51) REP(j,1,51) c[i][j] = c[i-1][j]+c[i-1][j-1];
		int n = hall.size(), m = hall[0].size();
		ll ans = 0;
		rep(i,n)
		{
			int t = 0;
			rep(j,m) if(hall[i][j]=='#') t++;
			ans += c[m-t][num];
		}
		if(num>1) rep(j,m)
		{
			int t = 0;
			rep(i,n) if(hall[i][j]=='#') t++;
			ans += c[n-t][num];
		}
		rep(i,num) ans *= i+1;
		return ans;
	}
};
