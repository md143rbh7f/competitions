#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define N 50
#define INF 1234567890

ll d[N][N], e[N][N], f[N], g[N];

struct NegativeGraphDiv1
{
ll findMin(int n, vi a, vi b, vi w, int c)
{
	int m = a.size();
	rep(i, n) rep(j, n) d[i][j] = e[i][j] = (i != j) * INF;
	rep(x, m)
	{
		a[x]--, b[x]--;
		acc(min, d[a[x]][b[x]], (ll) w[x]);
	}
	rep(k, n) rep(i, n) rep(j, n) acc(min, d[i][j], d[i][k] + d[k][j]);
	rep(i, n) f[i] = g[i] = d[0][i];
	for(bool start = true; c; c /= 2, start = false)
	{
		rep(i, n) rep(j, n)
		{
			if(start) rep(x, m) acc(min, e[i][j], d[i][a[x]] - w[x] + d[b[x]][j]);
			else rep(k, n) acc(min, e[i][j], d[i][k] + d[k][j]);
		}
		swap(d, e);
		if(c % 2)
		{
			rep(i, n) rep(j, n) acc(min, g[i], f[j] + d[j][i]);
			swap(f, g);
		}
	}
	return f[n - 1];
}
};
