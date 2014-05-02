#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define N 100005
#define S 333333
#define K 305

int best[K], a[N], b[N];
vector<int> ids[N];

int main()
{
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	rep(i, n) cin >> a[i];
	rep(j, m) cin >> b[j], ids[b[j]].push_back(j + 1);
	for(auto & id : ids) id.push_back(S + 1);
	range(k, 1, K) best[k] = S;
	int ans = 0;
	rep(i, n) for(int k = K - 1; k; k--)
	{
		best[k] = min(best[k], *upper_bound(all(ids[a[i]]), best[k-1]));
		if(i + 1 + best[k] + k * e <= s) ans = max(ans, k);
	}
	cout << ans << endl;
	return 0;
}
