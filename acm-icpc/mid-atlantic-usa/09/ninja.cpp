#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

#define N 1005
#define M 3*N
#define INF 1234567890

int n, m, d, lo, hi, h[N], x[N], u[M], v[M], l[M];

void edge(int a, int b, int c)
{
	u[m] = a, v[m] = b, l[m] = c, m++;
}

bool solve()
{
	cin >> n >> d;
	if(!n) return false;

	m = lo = hi = 0;
	rep(i, n)
	{
		cin >> h[i], x[i] = INF;
		if(h[i] < h[lo]) lo = i;
		if(h[i] > h[hi]) hi = i;
		if(i) edge(i - 1, i, -1);
	}

	rep(i, n)
	{
		int j = -1;
		rep(k, n) if(h[k] > h[i] && (j == -1 || h[k] < h[j])) j = k;
		if(j != -1) edge(i, j, d), edge(j, i, d);
	}

	x[min(lo, hi)] = 0;

	bool change;
	rep(t, n)
	{
		change = false;
		rep(i, m) if(x[u[i]] > x[v[i]] + l[i])
			x[u[i]] = x[v[i]] + l[i], change = true;
	}

	if(change) cout << -1 << endl;
	else cout << abs(x[lo] - x[hi]) << endl;

	return true;
}

int main()
{
	while(solve());
	return 0;
}
