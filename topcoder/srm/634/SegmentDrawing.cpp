#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

using vi = vector<int>;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

template <typename T>
struct Point {
T x, y;
inline Point & operator+=(const Point & o) { x += o.x, y += o.y; return *this; }
inline Point operator+(const Point & o) const { auto p = *this; return p += o; }
inline Point & operator-=(const Point & o) { x -= o.x, y -= o.y; return *this; }
inline Point operator-(const Point & o) const { auto p = *this; return p -= o; }
inline T operator*(const Point & o) { return x * o.x + y * o.y; }
inline T operator%(const Point & o) const { return x * o.y - y * o.x; }
inline bool operator==(const Point & o) const { return x == o.x && y == o.y; }
inline bool operator<(const Point & o) const { return x < o.x || (x == o.x && y < o.y); }
inline double r() const { return hypot(x, y); }
inline T q() const { return atan2(y, x); }
};
template <typename T> inline Point<T> operator*(T c, Point<T> a) { return {c * a.x, c * a.y}; }
template <typename T> inline Point<T> operator-(Point<T> a) { return -1 * a; }

template <typename T>
inline int sgn(T x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }

template <typename T>
struct Line {
	Point<T> a, b;
	inline bool intersects(const Line & o) const { return crosses(o) && o.crosses(*this); }

	private:
	inline bool crosses(const Line & o) const { return sgn((o.a - a) % (b - a)) * sgn((o.b - a) % (b - a)) <= 0; }
};

template <int SZ, typename T, T INF>
struct MaxFlowGraph {
void add_edge(int i, int j, T c = 1) {
	Edge* e = new Edge{j, c, 0, 0}, *f = new Edge{i, 0, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

T max_flow(int s, int t) {
	for (clr0(pre); bfs(s, t); clr0(pre));
	T ans = 0;
	for (auto e : g[s]) ans += e->f;
	return ans;
}

private:
struct Edge {
	int j;
	T c, f;
	Edge * r;
};

vector<Edge*> g[SZ];

Edge* pre[SZ];

T bfs(int s, int t) {
	queue<int> q({s});
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		for (auto e : g[i]) if (e->c > e->f && e->j != s && !pre[e->j])
			pre[e->j] = e, q.push(e->j);
	}
	if (!pre[t]) return 0;
	T f = INF;
	for (Edge* e = pre[t]; e; e = pre[e->r->j])
		f = min(f, e->c - e->f);
	for (Edge* e = pre[t]; e; e = pre[e->r->j])
		e->f += f, e->r->f -= f;
	return f;
}
};

constexpr int N = 200, INF = 123456789;
Line<int> ls[N];
MaxFlowGraph<2 * N, int, INF> flow_graph;

struct SegmentDrawing {
int maxScore(vi xs, vi ys, vi rs, vi bs) {
	int n = xs.size(), m = n * (n - 1) / 2, k = 2 * m + 2, id = 0, tot = 0;
	rep (i, n) range (j, i + 1, n) {
		int r = rs[i * n + j], b = bs[i * n + j];
		tot += r + b;
		flow_graph.add_edge(k - 2, id, r);
		flow_graph.add_edge(m + id, k - 1, b);
		ls[id++] = {{xs[i], ys[i]}, {xs[j], ys[j]}};
	}
	rep (i, m) rep (j, m) if (ls[i].intersects(ls[j]))
		flow_graph.add_edge(i, m + j, INF);
	return tot - flow_graph.max_flow(k - 2, k - 1);
}
};
