#include <iostream>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define N 5005
#define MAX 1e9

int t[N], l[N], r[N], c[N], a[N], s[N];

int main()
{
	int n, m;
	cin >> n >> m;
	rep(i,n) a[i] = MAX;
	rep(j,m)
	{
		cin >> t[j] >> l[j] >> r[j] >> c[j];
		l[j]--;
		if(t[j] == 1) range(i, l[j], r[j]) s[i] += c[j];
		else range(i, l[j], r[j]) acc(min, a[i], c[j] - s[i]);
	}
	rep(i,n) s[i] = 0;
	rep(j,m)
	{
		if(t[j] == 1) range(i, l[j], r[j]) s[i] += c[j];
		else
		{
			int big = -MAX;
			range(i, l[j], r[j]) acc(max, big, a[i] + s[i]);
			if(big != c[j])
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	rep(i,n) cout << a[i] << " ";
	cout << endl;
	return 0;
}
