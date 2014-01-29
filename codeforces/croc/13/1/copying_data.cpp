#include <iostream>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005
#define S 1<<18

int n, m, a[N], b[N], del[S];

#define next int j = 2 * i, k = 2 * i + 1, m = (l + r) / 2

void set(int _l, int _r, int _del, int i = 1, int l = 0, int r = n)
{
	if(_r <= l || r <= _l) return;
	if(_l <= l && r <= _r)
	{
		del[i] = _del;
		return;
	}
	next;
	if(del[i]) del[j] = del[k] = del[i];
	del[i] = 0;
	set(_l, _r, _del, j, l, m);
	set(_l, _r, _del, k, m, r);
}

int get(int x, int i = 1, int l = 0, int r = n)
{
	if(del[i]) return b[x + del[i]];
	if(l + 1 == r) return b[x];
	next;
	return x < m ? get(x, j, l, m) : get(x, k, m, r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	int t, x, y, k;
	while(m--)
	{
		cin >> t >> x;
		if(t == 1)
		{
			cin >> y >> k;
			set(y - 1, y - 1 + k, a + x - b - y);
		}
		else cout << get(x - 1) << endl;
	}
	return 0;
}
