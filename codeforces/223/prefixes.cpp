#include <iostream>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005

int m, n, type[N], val[N], len[N], cnt[N];
ll start[N];

int get(ll i)
{
	int a = 0, b = m - 1;
	while(a < b)
	{
		while(a < b)
		{
			int c = (a + b + 1) / 2;
			if(start[c] > i) b = c - 1;
			else a = c;
		}
		if(type[a] == 1) break;
		i = (i - start[a]) % len[a];
		b = a - 1;
		a = 0;
	}
	return val[a];
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> m;
	rep(i, m)
	{
		cin >> type[i];
		if(type[i] == 1)
		{
			cin >> val[i];
			start[i+1] = start[i] + 1;
		}
		else
		{
			cin >> len[i] >> cnt[i];
			start[i+1] = start[i] + (ll) len[i] * cnt[i];
		}
	}

	cin >> n;
	while(n--)
	{
		ll i;
		cin >> i;
		cout << get(i - 1) << (n ? " " : "\n");
	}

	return 0;
}
