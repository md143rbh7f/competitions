#include <iostream>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 200005

int n, m, init[N], tree[N], l[N], r[N], coeff[N];
vector<int> g[N];

void add(int i, int amt)
{
	for(; i <= n; i += i&(-i)) tree[i] += amt;
}

void upd(int v, int amt)
{
	amt *= coeff[v];
	add(l[v], amt), add(r[v] + 1, -amt);
}

int get(int v)
{
	int ans = 0;
	for(int i = l[v]; i; i -= i&(-i)) ans += tree[i];
	return init[v] + coeff[v] * ans;
}

int dfs(int v = 1, int p = 0, int c = 1, int i = 1)
{
	l[v] = i, coeff[v] = c;
	for(auto & u : g[v]) if(u != p) i = dfs(u, v, -c, i + 1);
	return r[v] = i;
}

int main()
{
	cin >> n >> m;
	rep(i, n) cin >> init[i+1];
	rep(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b), g[b].push_back(a);
	}
	dfs();
	rep(t, m)
	{
		int op, v;
		cin >> op >> v;
		if(op == 1)
		{
			int amt;
			cin >> amt;
			upd(v, amt);
		}
		else cout << get(v) << endl;
	}
	return 0;
}
