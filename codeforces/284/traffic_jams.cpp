#include <iostream>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005
#define T 60

struct Node
{
Node * l, * r;
int a, b, mt, dt[T];

void recompute()
{
	if(b - a > 1)
	{
		mt = l->mt;
		rep(t, T) dt[t] = r->query(l->query(t)) - t;
	}
	else rep(t, T) dt[t] = 1 + (t % mt == 0);
}

void update(int i, int _mt)
{
	if(i < a || b <= i) return;
	if(b - a == 1) mt = _mt;
	else l->update(i, _mt), r->update(i, _mt);
	recompute();
}

int query(int t, int i = 0, int j = N)
{
	if(j <= a || b <= i) return t;
	if(i <= a && b <= j) return t + dt[t % T];
	return r->query(l->query(t, i, j), i, j);
}

Node * init(int i, int j)
{
	a = i, b = j, l = r = nullptr;
	int c = (a + b) / 2;
	Node * ans = this + 1;
	if(b - a == 1) cin >> mt;
	else ans = (r = (l = ans)->init(a, c))->init(c, b);
	recompute();
	return ans;
}
};

Node buf[2 * N], * tree = buf;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, q;

	cin >> n;
	tree->init(0, n);

	cin >> q;
	string cmd;
	int x, y;
	rep(i, q)
	{
		cin >> cmd >> x >> y;
		x--;
		if(cmd[0] == 'A') cout << tree->query(0, x, y - 1) << endl;
		else tree->update(x, y);
	}

	return 0;
}
