#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 55

bool e[N][N];

struct PenguinSledding
{
	ll countDesigns( int n, vi a, vi b )
	{
		int m = a.size();
		rep(i,m) e[a[i]-1][b[i]-1] = e[b[i]-1][a[i]-1] = 1;

		ll ans = 1;
		rep(i,n)
		{
			int cnt = 0;
			rep(j,n) cnt += e[i][j];
			ans += ( 1ll << cnt ) - 1;
		}
		ans -= m;

		rep(i,n) REP(j,i+1,n) REP(k,j+1,n)
			ans += e[i][j] && e[j][k] && e[k][i];

		return ans;
	}
};
