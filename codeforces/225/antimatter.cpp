#include <iostream>
#include <utility>

using namespace std;

typedef long long ll;
#define M(x) ((x)%MOD)
#define buf(x) _##x[2*D+1],*x=_##x+D

#define D 5005
#define MOD 1000000007

int n, x;
ll ans, buf(a), buf(b);

int main()
{
	cin >> n;
	while(n--)
	{
		a[0] = M(a[0] + 1);
		cin >> x;
		for(int d = -D; d <= D; d++)
		{
			if(d + x <= D) b[d + x] = M(b[d + x] + a[d]);
			if(d - x >= -D) b[d - x] = M(b[d - x] + a[d]);
			a[d] = 0;
		}
		swap(a, b), ans = M(ans + a[0]);
	}
	cout << ans << endl;
	return 0;
}
