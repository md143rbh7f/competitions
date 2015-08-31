#include <algorithm>
#include <iostream>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

#define N 300005
#define K 5005
#define	INF 2000000002

int xs[N], ans[K][K];

int main()
{
	int n, k;
	cin >> n >> k;
	rep(i, n) cin >> xs[i];
	sort(xs, xs + n);
	int m = n / k, beta = n % k, alpha = k - beta;
	rep(a, alpha + 1) rep(b, beta + 1) if(a || b)
	{
		int i = a * m + b * (m + 1);
		int x = a ? ans[a - 1][b] + xs[i - 1] - xs[i - m] : INF;
		int y = b ? ans[a][b - 1] + xs[i - 1] - xs[i - m - 1] : INF;
		ans[a][b] = min(x, y);
	}
	cout << ans[alpha][beta] << endl;
	return 0;
}
