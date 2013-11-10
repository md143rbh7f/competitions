#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define MAX (1ll<<31)
#define N 2005

int n, k, a[N], b[N];

bool ok(ll l)
{
	rep(i,n)
	{
		b[i] = i;
		rep(j,i) if(fabs(a[i] - a[j]) <= l * (i - j))
			acc(min, b[i], b[j] + i - j - 1);
		if(b[i] + n - i - 1 <= k) return true;
	}
	return false;
}

int main()
{
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	ll ans = MAX - 1;
	for(ll d = MAX / 2; d; d /= 2) if(ok(ans - d)) ans -= d;
	cout << ans << endl;
	return 0;
}
