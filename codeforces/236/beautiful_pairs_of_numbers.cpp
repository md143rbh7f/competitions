#include <iostream>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

#define MOD 1000000007
#define N 1024
#define K 50

long long fac[N];
int choose[N+K][K], parts[N][K], ans[N][N];

int main()
{
	fac[0] = 1;
	range(n, 1, N) fac[n] = M(n * fac[n-1]);

	rep(n, N) choose[n][0] = 1;
	range(n, 1, N + K) range(k, 1, K)
		choose[n][k] = M(choose[n-1][k] + choose[n-1][k-1]);

	range(n, 1, N) parts[n][1] = 1;
	range(n, 1, N) range(k, 2, K)
		parts[n][k] = M(parts[n-k][k] + parts[n-k][k-1]);

	range(n, 1, N) range(k, 1, K) range(m, 1, n + 1)
		ans[n][k] = M(ans[n][k] + M(parts[m][k] * M(choose[n-m+k][k] * fac[k])));

	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		cout << ans[n][k] << endl;
	}
	return 0;
}
