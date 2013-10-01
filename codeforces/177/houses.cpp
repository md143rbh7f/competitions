#include <iostream>

using namespace std;

typedef long long ll;
#define iter(i,a,b,c) for(auto i=(a);i c(b);i++)
#define range(i,a,b) iter(i,a,b,<)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

#define MOD 1000000007

int n, k;

int main()
{
	int n, k;
	cin >> n >> k;
	long long ans = k;
	rep(i, k - 2) ans = M(ans * k);
	rep(i, n - k) ans = M(ans * (n - k));
	cout << ans << endl;
	return 0;
}
