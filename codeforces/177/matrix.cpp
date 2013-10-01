#include <algorithm>
#include <iostream>

using namespace std;

#define iter(i,a,b,c) for(auto i=(a);i c(b);i++)
#define range(i,a,b) iter(i,a,b,<)
#define rep(i,n) range(i,0,n)

#define N 10005

int n, m, d, a[N], t, ans;

int main()
{
	cin >> n >> m >> d;
	n *= m;
	rep(i,n) cin >> a[i];
	m = a[0] % d;
	rep(i,n)
	{
		a[i] -= m;
		if(a[i] % d)
		{
			cout << "-1" << endl;
			return 0;
		}
		a[i] /= d;
	}
	sort(a, a+n);
	rep(i,n) ans += abs(a[n/2] - a[i]);
	cout << ans << endl;
	return 0;
}
