#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)

#define N 2014

vector<int> g[N], h[N];
int n, c[N], nc, q[N], nq;
bool seen[N];

void dfs0(int x)
{
	if(seen[x]) return;
	seen[x] = true;
	for(auto y : g[x]) dfs0(y);
	q[nq++] = x;
}

void dfs1(int x)
{
	if(c[x] > -1) return;
	c[x] = nc;
	for(auto y : h[x]) dfs1(y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	rep(i, n) rep(j, n)
	{
		int t;
		cin >> t;
		if(t) g[i].push_back(j), h[j].push_back(i);
	}

	nq = 0;
	clr(seen);
	rep(i, n) dfs0(i);

	nc = 0;
	CLR(c, -1);
	for(int i = n - 1; i >= 0; i--) if(c[q[i]] == -1)
	{
		dfs1(q[i]);
		nc++;
	}

	cout << (nc == 1 ? "YES" : "NO") << endl;
	return 0;
}
