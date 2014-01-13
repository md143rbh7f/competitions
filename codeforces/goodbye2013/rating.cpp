#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 300005

pii a[N];
int ans[N];

int main()
{
	int n;
	cin >> n;
	rep(i, n) cin >> a[i].first, a[i].second = i;
	sort(a, a + n);
	int m = 0;
	rep(i, n)
	{
		m = max(m + 1, a[i].first);
		ans[a[i].second] = m;
	}
	rep(i, n) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
