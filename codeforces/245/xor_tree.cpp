#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005

vi g[N], ans;
bool a[N], b[N];

void rec(int u = -1, int v = 0, int e = 0, int o = 0)
{
	a[v] ^= e;
	if(a[v] != b[v]) ans.push_back(v + 1), e ^= 1;
	for(auto w : g[v]) if(w != u) rec(v, w, o, e);
}

int main()
{
	int n;
	cin >> n;

	rep(i, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}

	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	rec();
	cout << ans.size() << endl;
	for(auto v : ans) cout << v << endl;

	return 0;
}
