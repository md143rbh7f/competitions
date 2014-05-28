#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define N 75

int d[N][N];

int work(int a, int b)
{
	if(__gcd(a, b) == 1) return 0;
	int n = b - a + 1;
	if(n > N) return 1;
	rep(i, n) rep(j, n) if(i != j)
		d[i][j] = __gcd(a + i, a + j) == 1 ? 1 : N;
	rep(i, n) rep(j, n) rep(k, n)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	return d[0][n - 1] - 1;
}

struct EllysCoprimesDiv2
{
	int getCount(vi xs)
	{
		sort(all(xs));
		int ans = 0;
		rep(i, xs.size() - 1) ans += work(xs[i], xs[i + 1]);
		return ans;
	}
};
