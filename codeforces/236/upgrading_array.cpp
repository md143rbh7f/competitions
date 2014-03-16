#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 5005

set<int> bad;
int nums[N], gs[N];

int score(int n)
{
	int ans = 0;
	for(int p = 2; p * p <= n; p++) if(n % p == 0)
	{
		int d = bad.count(p) ? -1 : 1;
		while(n % p == 0) n /= p, ans += d;
	}
	if(n > 1) ans += bad.count(n) ? -1 : 1;
	return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> nums[i];
	rep(i, m)
	{
		int tmp;
		cin >> tmp;
		bad.insert(tmp);
	}

	int ans = 0;
	rep(i, n) ans += score(nums[i]);

	gs[0] = nums[0];
	range(i, 1, n) gs[i] = __gcd(gs[i-1], nums[i]);

	int g = 1;
	for(int i = n - 1; i >= 0; i--)
	{
		int h = gs[i] / g, d = -(i + 1) * score(h);
		if(d > 0) ans += d, g *= h;
	}
	cout << ans << endl;

	return 0;
}
