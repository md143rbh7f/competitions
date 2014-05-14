#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define range(i,a,b,d) for(auto i=(a);i!=b+d;i+=d)

#define N 1005

int a[N][N];
ll b[N][N], c[N][N], d[N][N], e[N][N];

void work(ll ans[N][N], int i0, int j0, int i1, int j1, int di, int dj)
{
	range(i, i0, i1, di) range(j, j0, j1, dj)
		ans[i][j] = a[i][j] + max(ans[i-di][j], ans[i][j-dj]);
}

int main()
{
	int n, m;
	cin >> n >> m;
	range(i, 1, n, 1) range(j, 1, m, 1) cin >> a[i][j];
	work(b, 1, 1, n, m, +1, +1);
	work(c, 1, m, n, 1, +1, -1);
	work(d, n, 1, 1, m, -1, +1);
	work(e, n, m, 1, 1, -1, -1);
	ll ans = 0;
	range(i, 2, n - 1, 1) range(j, 2, m - 1, 1)
		ans = max(ans,
			max(
				b[i - 1][j] + e[i + 1][j] + c[i][j + 1] + d[i][j - 1],
				b[i][j - 1] + e[i][j + 1] + c[i - 1][j] + d[i + 1][j]
			)
		);
	cout << ans << endl;
	return 0;
}
