#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 105
#define M 59
#define P 16

int ps[P] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int n, s, best[P][1<<P], cost[P][1<<P], mask[M], ans[N];
pair<int,int> a[N];

int rec(int i, int p)
{
	if(i == n - s) return 0;
	int & b = best[i][p], & c = cost[i][p];
	if(b) return c;
	b = -1, c = 1234567;
	range(k, 1, M)
	{
		int q = mask[k];
		if(q & p) continue;
		int d = abs(k - a[i + s].first) + rec(i + 1, p ^ q);
		if(d < c) c = d, b = k;
	}
	return c;
}

int main()
{
	rep(i, M) rep(j, P) mask[i] ^= (!(i % ps[j])) << j;
	cin >> n;
	rep(i, n) cin >> a[i].first, a[i].second = i;
	sort(a, a + n);
	if(n > P) s = n - P;
	rec(0, 0);
	int p = 0;
	rep(i, n)
	{
		if(i < s) ans[a[i].second] = 1;
		else
		{
			int k = best[i - s][p], q = mask[k];
			ans[a[i].second] = k, p ^= q;
		}
	}
	rep(i, n) cout << ans[i] << " ";
	return 0;
}
