#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 200005

int n, m, p, r, b, as[N], ans[N];
map<int,int> cnt;

void inc(int k, int v)
{
	cnt[k] += v;
	if(!cnt[k]) cnt.erase(k);
}

int main()
{
	cin >> n >> m >> p;
	if((m - 1ll) * p >= n) goto done;
	rep(i, n) cin >> as[i];
	rep(i, m)
	{
		cin >> b;
		cnt[b]++;
	}
	rep(q, p) for(int x = n - q - 1, y = x + m * p; y >= 0; x -= p, y -= p)
	{
		if(x >= 0) inc(as[x], -1);
		if(y < n) inc(as[y], 1);
		if(cnt.empty()) ans[r++] = x;
	}
	sort(ans, ans + r);
	done: cout << r << endl;
	rep(i, r) cout << ans[i] + 1 << " ";
	return 0;
}
