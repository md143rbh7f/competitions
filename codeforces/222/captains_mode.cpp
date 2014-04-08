#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 105
#define M 20

int n, m, x[N], ps[N], dp[1<<M];
string as[N];

int main()
{
	cin >> n;
	rep(i, n) cin >> x[i];
	sort(x, x + n, greater<int>());
	cin >> m;
	rep(i, m) cin >> as[i] >> ps[i];
	for(int s = (1<<m) - 2; s >= 0; s--)
	{
		int t = __builtin_popcount(s);
		int u = as[t] == "p", v = ps[t+1] == ps[t] ? 1 : -1;
		dp[s] = -123456789;
		rep(i, m) if(!((s >> i) & 1))
			dp[s] = max(dp[s], u * x[i] + v * dp[s ^ (1 << i)]);
	}
	cout << (ps[0] == 1 ? 1 : -1) * dp[0] << endl;
	return 0;
}
