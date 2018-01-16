#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define rq(x) query<decltype(&Node::x),&Node::x>

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

struct Node {
int s, d;

inline void init(int a, int b) { s = d = 0; }

inline void push(Node *l, Node *r, int a, int b, int c) {
	l->d += d, r->d += d, d = 0;
}

inline void collect(Node *l, Node *r, int a, int b, int c) {
	s = max(l->get(), r->get());
}

inline int get() { return s + d; }

inline void incr(int a, int b) { d++; }
inline void get_max(int a, int b, int &v) { v = max(v, get()); }
inline void set(int a, int b, int v) { s = v; }
};

struct Iv {
bool t;
int a, b;

inline bool operator<(const Iv & o) const {
	if (t != o.t) return t < o.t;
	if (b != o.b) return b < o.b;
	if (a != o.a) return a < o.a;
	return false;
}
};

constexpr int N = 50005;

char buf[5];
Iv xs[N];
SegmentTree<Node, N> tree[2];

void work() {
	int m, k;
	scanf("%d%d", &m, &k);
	tree[0].init(m + 1);
	tree[1].init(m + 1);

	rep (i, k) {
		scanf("%s", buf);
		xs[i].t = buf[0] == 'E' || buf[0] == 'C';
	}
	rep (i, k) scanf("%d", &xs[i].a);
	rep (i, k) scanf("%d", &xs[i].b);

	int j = 0;
	rep (i, k) if (xs[i].a < xs[i].b) xs[j++] = xs[i];
	int n = j;

	sort(xs, xs + n);

	Iv *x0 = xs, *x1 = xs;
	while (x1 < xs + n && !x1->t) x1++;

	j = 0;
	Iv *y0 = x1, *y1 = xs + n;
	rep (i, m + 1) {
		for (; x0 < x1 && x0->b == i; x0++) tree[0].rq(incr)(0, x0->a + 1);
		for (; y0 < y1 && y0->b == i; y0++) tree[1].rq(incr)(0, y0->a + 1);
		int best0 = 0, best1 = 0;
		tree[0].rq(get_max)(0, i, best0);
		tree[1].rq(get_max)(0, i, best1);
		tree[0].rq(set)(i, i + 1, best1);
		tree[1].rq(set)(i, i + 1, best0);
		int best = max(best0, best1);
		for (; j < best; j++) {
			printf("%d ", i);
		}
	}
	for (; j < k; j++) printf("-1 ");
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}
