#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)

#define N 100005
#define M 5

int n, k, op[N], arg[N], nums[N];
map<int,int> id;

struct node
{
	int l, r, m, sz;
	ll s[M];
	node * lc, * rc;

	node(int _l = 0, int _r = k) : l(_l), r(_r), m((l + r) / 2), sz(0)
	{
		clr(s); // haha, CLRS, get it?
		if(l + 1 < r) lc = new node(l, m), rc = new node(m, r);
	}

	void upd(int i, int d)
	{
		sz += d;
		if(l + 1 == r)
		{
			s[0] = sz * nums[l];
			return;
		}
		if(i < m) lc->upd(i, d);
		else rc->upd(i, d);
		rep(i, M) s[i] = lc->s[i] + rc->s[(M + (i - lc->sz)%M)%M];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	string s;
	rep(i, n)
	{
		cin >> s;
		op[i] = (s[0] == 'a') - (s[0] == 'd');
		if(op[i])
		{
			cin >> arg[i];
			id[arg[i]] = 0;
		}
	}

	k = id.size();
	int t = 0;
	for(auto & kv : id) nums[t] = kv.first, kv.second = t++;
	rep(i, n) if(op[i]) arg[i] = id[arg[i]];

	node tree;
	rep(i, n)
	{
		if(op[i]) tree.upd(arg[i], op[i]);
		else cout << tree.s[M/2] << endl;
	}
	return 0;
}
