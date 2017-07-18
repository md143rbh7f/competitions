#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define acc(f,x,y) x=f(x,y)
#define fst first
#define snd second

constexpr int N = 27, INF = 1234567890;
typedef pair<vector<char>, int> state;

int n, g[2][N];
char e[N][N];
map<state, int> mem;
vector<pii> grps;

pii rec(int c, int i, int gid) {
	if(g[c][i]) return {0, 0};
	pii grp {!c, c};
	g[c][i] = gid;
	rep(j, n) if(c ? e[j][i] : e[i][j]) {
		pii nxt = rec(!c, j, gid);
		grp.fst += nxt.fst, grp.snd += nxt.snd;
	}
	return grp;
}

int brute(vector<char> & s, int x, int y) {
	state key {s, x};
	if(mem.count(key)) return mem[key];

	int & ans = mem[key] = INF;
	rep(i, grps.size()) if(s[i]) {
		vector<char> s_(s);
		s_[i]--;

		int gx = grps[i].fst, gy = grps[i].snd;
		int x_ = x + gx, y_ = y + gy;
		if(x_ == y_) x_ = 0, y_ = 0;

		acc(min, ans, brute(s_, x_, y_) + gx * y + gy * x);
	}

	if(ans == INF) ans = 0;
	return ans;
}

int work() {
	scanf("%d", &n);
	rep(i, n) {
		scanf("%s", e[i]);
		rep(j, n) e[i][j] -= '0';
	}

	int gid = 1;
	clr0(g);
	map<pii, int> dist;
	rep(c, 2) rep(i, n) if(!g[c][i]) dist[rec(c, i, gid++)]++;

	int miss = 0;
	rep(i, n) rep(j, n) miss += g[0][i] == g[1][j] && !e[i][j];

	grps.clear();
	vector<char> s0;
	for(auto p : dist) grps.push_back(p.fst), s0.push_back(p.snd);

	mem.clear();
	return miss + brute(s0, 0, 0);
}

int main() {
	int t;
	scanf("%d", &t);
	rep(i, t) printf("Case #%d: %d\n", i + 1, work());
	return 0;
}
