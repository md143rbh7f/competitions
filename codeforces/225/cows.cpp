#include <iostream>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

int main()
{
	int n;
	cin >> n;
	ll ans = 0;
	int cnt = 0;
	rep(i, n)
	{
		int x;
		cin >> x;
		if(x) cnt++;
		else ans += cnt;
	}
	cout << ans << endl;
	return 0;
}
