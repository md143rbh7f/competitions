#include <iostream>
#include <map>
#include <utility>

using namespace std;

#define a first
#define b second
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

void merge(map<int, int> & is)
{
	map<int, int> js;
	int v0 = 0;
	for(auto & i : is)
	{
		int v1 = v0 + i.b;
		if((v1 > 0) != (v0 > 0)) js[i.a] = (v1 > 0) - (v0 > 0);
		v0 = v1;
	}
	is = move(js);
}

void expand(map<int, int> & is, int d)
{
	map<int, int> js;
	for(auto & i : is) js[i.a - d * i.b] += i.b;
	merge(js);
	is = move(js);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	map<int, map<int, int>> bad;
	rep(i, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		bad[x + y][x - y]--, bad[x + y][x - y + 2]++;
	}

	int _u = 0;
	map<int, int> can = {{0, 1}, {2, -1}};
	for(auto & diag : bad)
	{
		int u = diag.a;
		expand(can, u - _u);
		auto & vs = diag.b;
		for(auto & v : vs) can[v.a] += v.b;
		merge(can), _u = u;
	}
	expand(can, 2 * n - 2 - _u);

	int d = 0;
	for(auto i : can)
	{
		if(i.a > 0) break;
		d = i.b;
	}
	cout << (d == 1 ? 2 * n - 2 : -1) << endl;
	return 0;
}
