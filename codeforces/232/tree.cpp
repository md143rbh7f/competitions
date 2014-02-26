#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define MOD 1000000007
#define M(x) ((MOD+(x)%MOD)%MOD)
#define N 300005

vi g[N], qs[N];

struct Add { int t, x, k; };
vector<Add> adds[N];

struct Node
{
	int ks, xs, l, r, ans, del;
	Node * lc, * rc;

	Node(int l, int r)
	: l(l), r(r), ks(0), xs(0), ans(0), del(0), lc(NULL), rc(NULL)
	{
		if(r - l == 1) return;
		int m = (l + r) / 2;
		lc = new Node(l, m), rc = new Node(m, r);
	}

	void clean()
	{
		if(!del) return;
		ans = M(ans + (long long) del * ks);
		if(lc) lc->del += del, rc->del += del;
		del = 0;
	}

	void put(int t, int x, int k)
	{
		if(t < l || t >= r) return;
		clean();
		ks = M(ks + k), xs = M(xs + x), ans = M(ans + x);
		if(lc) lc->put(t, x, k), rc->put(t, x, k);
	}

	int get(int t)
	{
		if(t <= l) return 0;
		clean();
		if(t >= r) return ans;
		return M(lc->get(t) + rc->get(t));
	}
};
Node * tree;

bool need[N];
int ans[N];

void rec(int v)
{
	for(auto & a : adds[v]) tree->put(a.t, a.x, a.k);
	for(auto & t : qs[v]) ans[t] = tree->get(t + 1);
	tree->del--;
	for(auto & u : g[v]) rec(u);
	tree->del++;
	for(auto & a : adds[v]) tree->put(a.t, -a.x, -a.k);
}

int main()
{
	int n;
	cin >> n;
	rep(i, n - 1)
	{
		int p;
		cin >> p;
		g[p-1].push_back(i + 1);
	}

	int q;
	cin >> q;
	rep(t, q)
	{
		int type, v;
		cin >> type >> v;
		if(type == 1)
		{
			int x, k;
			cin >> x >> k;
			adds[v-1].push_back({t, x, k});
		}
		else qs[v-1].push_back(t), need[t] = true;
	}

	tree = new Node(0, q);
	rec(0);

	rep(t, q) if(need[t]) cout << ans[t] << endl;
	
	return 0;
}
