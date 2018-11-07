/*
 * This is an example of how one might set up a lazy segment tree which supports
 * the following operations in logarithmic time:
 *
 *	1. Range update: for k in {i, ..., j - 1}, add delta to X[k].
 *
 *	2. Range query: return sum(X[k] for k in {i, ..., j - 1}).
 */

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
ll s, d;

inline void init(int a, int b) { s = d = 0; }

inline void push(Node *l, Node *r, int a, int b, int c) {
	l->d += d, r->d += d, d = 0;
}

inline void collect(Node *l, Node *r, int a, int b, int c) {
	s = l->get(a, c) + r->get(c, b);
}

inline ll get(int a, int b) { return s + (b - a) * d; }

inline void add(int a, int b, int v) { d += v; }
inline void sum(int a, int b, ll &s) { s += get(a, b); }
};
