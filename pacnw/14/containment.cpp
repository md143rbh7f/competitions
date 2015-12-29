#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

constexpr int INF = 12345, S = 10, N = 1005;

struct Edge {
	int j, c, f;
	Edge * r;
};

vector<Edge*> g[N];
int n = N;

void add_edge(int i, int j, int c = 1) {
	Edge* e = new Edge{j, c, 0, 0}, *f = new Edge{i, 0, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

Edge* pre[N];

int bfs(int s, int t) {
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int i = q.front();
		q.pop();
		for(auto e : g[i]) if(e->c > e->f && e->j != s && !pre[e->j])
			pre[e->j] = e, q.push(e->j);
	}
	if(!pre[t]) return 0;
	int f = INF;
	for(Edge* e = pre[t]; e; e = pre[e->r->j])
		f = min(f, e->c - e->f);
	for(Edge* e = pre[t]; e; e = pre[e->r->j])
		e->f += f, e->r->f -= f;
	return f;
}

int max_flow(int s, int t) {
	for(clr0(pre); bfs(s, t); clr0(pre));
	int ans = 0;
	for(auto e : g[s]) ans += e->f;
	return ans;
}

inline bool ok(int x, int y, int z) {
	return 0 <= x && x < S
		&& 0 <= y && y < S
		&& 0 <= z && z < S;
}
inline int id(int x, int y, int z) {
	return (x * S + y) * S + z;
}

void connect(int x0, int y0, int z0, int x1, int y1, int z1) {
	if(ok(x0, y0, z0)) add_edge(id(x0, y0, z0), id(x1, y1, z1));
	else add_edge(N - 2, id(x1, y1, z1));
}

int solve() {
	rep(x, S) rep(y, S) rep(z, S) {
		connect(x - 1, y, z, x, y, z);
		connect(x + 1, y, z, x, y, z);
		connect(x, y - 1, z, x, y, z);
		connect(x, y + 1, z, x, y, z);
		connect(x, y, z - 1, x, y, z);
		connect(x, y, z + 1, x, y, z);
	}

	int m, x, y, z;
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d%d", &x, &y, &z);
		add_edge(id(x, y, z), N - 1, INF);
	}

	int ans = max_flow(N - 2, N - 1);

	rep(i, N) {
		for(auto e : g[i]) delete e;
		g[i].clear();
	}

	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) printf("%d\n", solve());
	return 0;
}
