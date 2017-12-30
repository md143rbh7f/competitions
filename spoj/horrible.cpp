#include <cstdio>
#include <utility>

using namespace std;

using ll = long long;
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

constexpr int N = 100005;

SegmentTree<Node, N> tree;

void work() {
	int n, c, t, i, j, v;
	ll s;
	scanf("%d%d", &n, &c);
	tree.init(n);
	while (c--) {
		scanf("%d%d%d", &t, &i, &j);
		i--;
		if (t == 0) {
			scanf("%d", &v);
			tree.rq(add)(i, j, v);
		} else {
			s = 0;
			tree.rq(sum)(i, j, s);
			printf("%lld\n", s);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}
