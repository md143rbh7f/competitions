#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)
#define M(x) ((x)%MOD)

#define B 11
#define MOD 1000000007

ll x[1<<B][2][2], y[1<<B][2][2];
int n, m, k;

int solve(int b)
{
	clr(x);
	x[0][0][0] = 1;
	int p = 1<<(B - b - 1);
	range(i, 1, k)
	{
		int i0 = i >> (b + 1), i1 = (i >> b) & 1;
		rep(j, p) rep(u, 2) rep(v, 2)
		{
			if(i <= n) y[j^i0][u^i1][v] = M(y[j^i0][u^i1][v] + x[j][u][v]);
			if(i <= m) y[j^i0][u][v^i1] = M(y[j^i0][u][v^i1] + x[j][u][v]);
		}
		rep(j, p) rep(u, 2) rep(v, 2)
		{
			x[j][u][v] = M(x[j][u][v] + y[j][u][v]);
			y[j][u][v] = 0;
		}
	}
	return x[0][0][1];
}

struct WinterAndSnowmen
{
	int getNumber(int _n, int _m)
	{
		n = _n, m = _m, k = max(n, m) + 1;
		int ans = 0;
		rep(b, B) ans = M(ans + solve(b));
		return ans;
	}
};
