/*
 * This is an example of how one might set up a lazy segment tree which supports
 * the following operations in logarithmic time:
 *
 *	1. Point update: set X[i] = x.
 *
 *	2. Range update: for k in {i, ..., j - 1}, add delta to X[i].
 *
 *	3. Range query: return sum(X[k] for k in {i, ..., j - 1}).
 *
 * N.B. The way the l and r child pointers are defined. Whenever SZ, the size of
 * the range represented, is not a power of two, the 'standard' method of
 * defining l and r as 2i and 2i + 1, respectively, leaves many gaps in the
 * buffer array. At worst, the largest index may be around 4SZ, even though only
 * 2SZ - 1 nodes are needed. In the following code, the l and r pointers are
 * specifically defined to remove the gaps, while also keeping the tree balanced
 * and only creating 2SZ - 1 nodes.
 */

template <int SZ>
struct SegmentTree {

struct Node {
ll s, d;

#define decl_children \
	Node *l = this + 1, *r = this + ((b - a) & -2); \
	int c = (a + b) / 2

inline void push(Node *l, Node *r) {
	l->d += d, r->d += d;
	d = 0;
}

inline ll get(int a, int b) { return s + (b - a) * d; }

inline void collect(Node *l, Node *r, int a, int c, int b) {
	s = l->get(a, c) + r->get(c, b);
}

void init(int a, int b) {
	d = 0;
	if (b - a == 1) {
		s = 0;
		return;
	}
	decl_children;
	l->init(a, c), r->init(c, b);
	collect(l, r, a, c, b);
}

void set(int a, int b, int i, int v) {
	if (i < a || b <= i) return;
	if (i == a && b == i + 1) {
		s = v, d = 0;
		return;
	}
	decl_children;
	push(l, r);
	l->set(a, c, i, v), r->set(c, b, i, v);
	collect(l, r, a, c, b);
}

void add(int a, int b, int i, int j, int v) {
	if (j <= a || b <= i) return;
	if (i <= a && b <= j) {
		d += v;
		return;
	}
	decl_children;
	push(l, r);
	l->add(a, c, i, j, v), r->add(c, b, i, j, v);
	collect(l, r, a, c, b);
}

ll sum(int a, int b, int i, int j) {
	if (j <= a || b <= i) return 0;
	if (i <= a && b <= j) return get(a, b);
	decl_children;
	push(l, r);
	ll ans = l->sum(a, c, i, j) + r->sum(c, b, i, j);
	collect(l, r, a, c, b);
	return ans;
}
};

int n;
Node n0[2 * SZ];

void init(int n) { n0->init(0, this->n = n); }
void set(int i, int v) { n0->set(0, n, i, v); }
void add(int i, int j, int v) { n0->add(0, n, i, j, v); }
ll sum(int i, int j) { return n0->sum(0, n, i, j); }
};
