#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)
#define snd second

constexpr int MOD = 1000000007, N = 100005;

int xs[N], ys[N], max_x[N], max_y[N];
map<int, int> xc, yc;

void gen(int n, ll a, ll b, ll c, int * vs, map<int, int> & cv) {
	vs[0] = a;
	range(i, 1, n) vs[i] = M(b * vs[i - 1] + c);
	rep(i, n) cv[vs[i]] = 0;
	int sz = 0;
	for(auto & p : cv) p.snd = sz++;
}

void compute_max(int n, int * vs, int * us, map<int, int> & cu, int * max_v) {
	rep(i, n) acc(max, max_v[cu[us[i]]], vs[i]);
	for(int i = cu.size() - 1; i; i--) acc(max, max_v[i - 1], max_v[i]);
}

bool work(int t, int m) {
	int x = max_x[0];
	rep(i, m) {
		auto next = yc.upper_bound(max_y[xc.lower_bound(x - t)->snd] + t);
		if(next == yc.end()) return true;
		x = max_x[next->snd];
	}
	return false;
}

struct TheEmpireStrikesBack {
int find(int ax, int bx, int cx, int ay, int by, int cy, int n, int m) {
	gen(n, ax, bx, cx, xs, xc);
	gen(n, ay, by, cy, ys, yc);
	compute_max(n, xs, ys, yc, max_x);
	compute_max(n, ys, xs, xc, max_y);
	int a = 0, b = MOD;
	while(a < b) {
		int c = (a + b) / 2;
		if(work(c, m)) b = c;
		else a = c + 1;
	}
	return a;
}
};
