#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define M(x) ((x)%MOD)
#define rq(x) query<decltype(&Node<S>::x),&Node<S>::x>

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

template <int S>
struct Node {
int cnt[S], d;

inline void init(int a, int b) {
	if (b - a == 1) {
		int x;
		scanf("%d", &x);
		if (x < S) cnt[x] = 1;
	}
}

inline void push(Node *l, Node *r, int a, int b, int c) {
	l->d += d, r->d += d, d = 0;
}

inline void collect(Node *l, Node *r, int a, int b, int c) {
	clr0(cnt), l->add_to(cnt), r->add_to(cnt);
}

inline void add_to(int *o) { rep (i, S - d) o[i + d] += cnt[i]; }

inline void incr(int a, int b) { d++; }
inline void sum(int a, int b, int *o) { add_to(o); }
inline void set(int a, int b, int v) {
	clr0(cnt);
	d = 0;
	if (v < S) cnt[v] = b - a;
}
};

constexpr int N = 100005, S = 40, MOD = 1e9;
ll fac[S];
int ans[S];
SegmentTree<Node<S>, N> tree;

int main() {
	fac[0] = 1;
	range (i, 1, S) fac[i] = M(i * fac[i - 1]);

	int n, m, t, x, y;
	scanf("%d%d", &n, &m);
	tree.init(n);

	rep (_, m) {
		scanf("%d%d%d", &t, &x, &y);
		x--;
		if (t == 1) tree.rq(incr)(x, y);
		else if (t == 2) {
			clr0(ans);
			tree.rq(sum)(x, y, ans);
			int tot = 0;
			rep (i, S) tot = M(tot + M(fac[i] * ans[i]));
			printf("%d\n", tot);
		} else tree.rq(set)(x, x + 1, y);
	}

	return 0;
}
