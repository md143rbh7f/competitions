#include <iostream>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 1005

int a[N];

int solve()
{
	int n;
	cin >> n;
	rep(i, n) cin >> a[i];

	int ans = 0, l = 0, r = n - 1;
	rep(t, n)
	{
		int m = l;
		range(i, l, r + 1) if(a[i] < a[m]) m = i;
		int ml = m - l, mr = r - m;
		if(ml < mr)
		{
			for(int i = m; i > l; i--) a[i] = a[i - 1];
			ans += ml, l++;
		}
		else
		{
			range(i, m, r) a[i] = a[i + 1];
			ans += mr, r--;
		}
	}

	return ans;
}

int main()
{
	int nc;
	cin >> nc;
	for(int i = 1; i <= nc; i++)
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
