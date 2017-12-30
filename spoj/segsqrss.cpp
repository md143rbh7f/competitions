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
ll s, s2;
bool is_set;
int x, d;

inline void init(int a, int b) {
	is_set = false;
	x = d = 0;
	if (b - a == 1) {
		scanf("%lld", &s);
		s2 = s * s;
	}
}

inline void push(Node *l, Node *r, int a, int b, int c) {
	if (is_set) {
		l->is_set = r->is_set = true;
		l->x = r->x = x;
		l->d = r->d = d;
		is_set = false;
	} else l->d += d, r->d += d;
	d = 0;
}

inline void collect(Node *l, Node *r, int a, int b, int c) {
	s = l->get(a, c) + r->get(c, b);
	s2 = l->get2(a, c) + r->get2(c, b);
}

inline ll get(int a, int b) { return is_set ? (ll) (b - a) * x : s; }

inline ll get2(int a, int b) {
	ll sum = get(a, b);
	ll sum2 = is_set ? sum * x : s2;
	return sum2 + 2 * sum * d + (ll) (b - a) * d * d;
}

inline void set(int a, int b, int v) { is_set = true, x = v, d = 0; }
inline void add(int a, int b, int v) { d += v; }
inline void sum(int a, int b, ll &s) { s += get2(a, b); }
};

constexpr int N = 100005;

SegmentTree<Node, N> tree;

void work() {
	int n, q, t, i, j, v;
	ll s;
	scanf("%d%d", &n, &q);
	tree.init(n);
	while (q--) {
		scanf("%d%d%d", &t, &i, &j);
		i--;
		if (t == 0) {
			scanf("%d", &v);
			tree.rq(set)(i, j, v);
		} else if (t == 1) {
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
	rep (i, t) {
		printf("Case %d:\n", i + 1);
		work();
	}
	return 0;
}
