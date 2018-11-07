#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using pii = pair<int,int>;
using vi = vector<int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

template <typename T, int SZ>
struct SegmentTree {
int n, i, j;
T p0[2 * SZ];

template <typename F, F f, bool all = false, typename ... A>
void rec(T *p, int a, int b, A &&... _) {
	if (all) {
		(p->*f)(a, b, forward<A>(_)...);
		if (b - a == 1) return;
	} else {
		if (j <= a || b <= i) return;
		if (i <= a && b <= j) return (p->*f)(a, b, forward<A>(_)...);
	}
	T *l = p + 1, *r = p + ((b - a) & -2);
	int c = (a + b) / 2;
	if (!all) p->push(l, r, a, b, c);
	rec<F, f, all>(l, a, c, forward<A>(_)...);
	rec<F, f, all>(r, c, b, forward<A>(_)...);
	p->collect(l, r, a, b, c);
}

template <typename ... A>
void init(int n, A &&... _) {
	this->n = n;
	rec<decltype(&T::init), &T::init, true>(p0, 0, n, forward<A>(_)...);
}

template <typename F, F f, typename ... A>
void query(int i, int j, A &&... _) {
	this->i = i, this->j = j;
	rec<F, f>(p0, 0, n, forward<A>(_)...);
}
};

#define rq(f) query<decltype(&Node::f),&Node::f>

struct Node {
int lo, cnt, d;

inline void init(int a, int b) { lo = 0, cnt = b - a, d = 0; }

inline void push(Node *l, Node *r, int a, int b, int c) {
	l->d += d, r->d += d;
	d = 0;
}

inline void collect(Node *l, Node *r, int a, int b, int c) {
	lo = min(l->get_lo(), r->get_lo());
	cnt = 0;
	if (l->get_lo() == lo) cnt += l->cnt;
	if (r->get_lo() == lo) cnt += r->cnt;
}

inline int get_lo() { return lo + d; }
inline void add(int a, int b, int x) { d += x; }
inline void sum(int a, int b, int &t) { if (get_lo() == 0) t += cnt; }
};

constexpr int N = 200005, H = 18;

SegmentTree<Node, N> tree;
vi g[N];
int p[N][H], h[N], t0[N], t1[N];

void dfs(int u, int w, int &t) {
	h[u] = h[w] + 1;
	p[u][0] = w;
	rep (b, H - 1) p[u][b + 1] = p[p[u][b]][b];
	t0[u] = t++;
	for (auto v : g[u]) if (v != w) dfs(v, u, t);
	t1[u] = t;
}

int up(int u, int i) {
	rep (b, H) if ((i >> b) & 1) u = p[u][b];
	return u;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	rep (_, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b), g[b].push_back(a);
	}

	int t = 0;
	dfs(1, 0, t);
	tree.init(n);

	set<pii> es;
	rep (_, q) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (make_pair(h[a], a) > make_pair(h[b], b)) swap(a, b);

		int x;
		auto it = es.find({a, b});
		if (it == es.end()) {
			x = 1;
			es.insert({a, b});
		} else {
			x = -1;
			es.erase(it);
		}

		int c = h[a] < h[b] ? up(b, h[b] - h[a] - 1) : 0;
		if (p[c][0] == a) {
			tree.rq(add)(t0[c], t1[c], x);
			tree.rq(add)(t0[b], t1[b], -x);
		} else {
			tree.rq(add)(0, n, x);
			tree.rq(add)(t0[a], t1[a], -x);
			tree.rq(add)(t0[b], t1[b], -x);
		}

		int s = 0;
		tree.rq(sum)(0, n, s);
		printf("%d\n", s);
	}

	return 0;
}
