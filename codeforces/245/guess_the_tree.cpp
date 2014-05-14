#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

int n, k, d[11], t[11];
vi sz;

bool rec(int x)
{
	if(x == n - 1)
	{
		int m = 0;
		rep(i, n)
		{
			if(t[i] >= sz[i]) return false;
			int p = sz[i] - 1 - t[i];
			if(d[i] + p < 2) return false;
			m += p;
		}
		return m == k;
	}
	range(y, x + 1, n)
	{
		d[y]++, t[y] += sz[x];
		if(rec(x + 1)) return true;
		d[y]--, t[y] -= sz[x];
	}
	return false;
}

bool work()
{
	cin >> n;
	rep(i, n)
	{
		int s;
		cin >> s;
		if(s == 1) k++;
		else if(s == 2) return false;
		else sz.push_back(s);
	}
	if(2 * k < n) return false;
	sort(all(sz));
	n -= k;
	if(!n) return k == 1;
	return rec(0);
}

int main()
{
	cout << (work() ? "YES" : "NO") << endl;
	return 0;
}
