#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>

using namespace std;

typedef unsigned long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005

int n, m, a[N], b[N];

ll get()
{
	ll sb = accumulate(b, b + m, 0ll), ans = ULLONG_MAX, acc = 0;
	sort(a, a + n);
	rep(i, n) ans = min(ans, sb * (n - i) + acc), acc += a[i];
	return ans;
}

int main()
{
	cin >> n >> m;
	rep(i, n) cin >> a[i];
	rep(j, m) cin >> b[j];
	ll ans0 = get();
	swap(n, m), swap(a, b);
	ll ans1 = get();
	cout << min(ans0, ans1);
	return 0;
}
