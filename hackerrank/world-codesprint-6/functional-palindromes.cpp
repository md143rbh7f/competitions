#include <algorithm>
#include <cstdio>
#include <map>
#include <tuple>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)
#define fst first
#define snd second
#define tup make_tuple

constexpr ll MOD = 1000000007, A = 100001, A_INV = 943660570;
constexpr int N = 100005;

int n, nq;
char s[N];
ll qs[N];

ll mod_pow(ll a, int b) {
	if (!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

ll _f[N];
void make_f() {
	rep (i, n) _f[i + 1] = M((ll) A * _f[i] + s[i]);
}

ll f(int k, int m) {
	return M(_f[m] - M(mod_pow(A, m - k) * _f[k]) + MOD);
}

template <int SZ>
struct SuffixArray {
int *suf, *ord, *lcp;

template <typename T>
void process(T s0, T s1) {
	int n = s1 - s0, r = 0, *buf = _buf, *s = alloc(buf, n + 3);
	suf = alloc(buf, n);
	for (int *t = s; s0 != s1; s0++, t++) r = max(r, (*t = *s0 + 1));
	s[n] = s[n + 1] = s[n + 2] = 0;
	rec(s, suf, n, r + 1, buf);

	lcp = alloc(buf, n), ord = alloc(buf, n);
	int l = 0;
	rep (i, n) ord[suf[i]] = i;
	rep (i, n) {
		if (ord[i] < n - 1) {
			int j = suf[ord[i] + 1];
			while (i + l < n && j + l < n && s[i + l] == s[j + l]) l++;
			lcp[ord[i]] = l;
		}
		else l = 0;
		if (l) l--;
	}
}

private:
int _buf[6 * SZ + 50];

inline int *alloc(int *(&buf), int sz) {
	int *a = buf;
	buf += sz;
	return a;
}

void radix_sort(int *s, int *suf0, int *suf1, int m, int r, int *c) {
	rep (i, r) c[i] = 0;
	rep (i, m) c[s[suf0[i]]]++;
	int t = 0;
	rep (i, r) tie(c[i], t) = tup(t, t + c[i]);
	rep (i, m) suf1[c[s[suf0[i]]]++] = suf0[i];
}

void rec(int *s, int *suf, int n, int r, int *buf) {
	int n0 = (n + 2) / 3, n2 = n / 3, nx = n0 + n2;
	int *ax = alloc(buf, nx + 3), *bx = alloc(buf, nx);
	ax[nx] = ax[nx + 1] = ax[nx + 2] = 0;

	int *a1 = ax, *a2 = ax + n0;
	rep (i, n0) a1[i] = 3 * i + 1;
	rep (i, n2) a2[i] = 3 * i + 2;
	radix_sort(s + 2, ax, bx, nx, r, buf);
	radix_sort(s + 1, bx, ax, nx, r, buf);
	radix_sort(s, ax, bx, nx, r, buf);

	int ord = 0;
	auto x = tup(-1, -1, -1);
	range (b, bx, bx + nx) {
		auto y = tup(s[*b], s[*b + 1], s[*b + 2]);
		if (y > x) ord++, x = y;
		(*b % 3 == 1 ? a1 : a2)[*b / 3] = ord;
	}

	if (ord < nx) {
		rec(ax, bx, nx, ord + 1, buf);
		rep (i, nx) {
			ax[bx[i]] = i + 1;
			bx[i] = bx[i] < n0 ? 3 * bx[i] + 1 : 3 * (bx[i] - n0) + 2;
		}
	}

	int *a0 = alloc(buf, n0), *b0 = alloc(buf, n0);
	ord = 0;
	range (b, bx, bx + nx) if (*b % 3 == 1) a0[ord++] = *b - 1;
	radix_sort(s, a0, b0, n0, r, buf);

	int *e0 = b0 + n0, *ex = bx + nx;
	bx += n % 3 == 1;
	while (b0 < e0 && bx < ex)
		*(suf++) = (
			*bx % 3 == 1
			? tup(s[*b0], a1[*b0 / 3]) < tup(s[*bx], a2[*bx / 3])
			: tup(s[*b0], s[*b0 + 1], a2[*b0 / 3]) < tup(s[*bx], s[*bx + 1], a1[*bx / 3 + 1])
		) ? *b0++ : *bx++;
	while (b0 < e0) *(suf++) = *b0++;
	while (bx < ex) *(suf++) = *bx++;
}
};

SuffixArray<N> sa;

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

#define rq(x) query<decltype(&MinNode::x),&MinNode::x>

struct MinNode {
int x;

inline void init(int a, int b, int *lcp) {
	if (b - a == 1) x = sa.lcp[a];
}

inline void push(MinNode *l, MinNode *r, int a, int b, int c) {}

inline void collect(MinNode *l, MinNode *r, int a, int b, int c) {
	x = min(l->x, r->x);
}

inline void query(int a, int b, int &v) { v = min(v, x); }
};

SegmentTree<MinNode, N> lcp_tree;

template <int SZ, int C=26>
struct PalindromeTree  {
struct Node {
	Node *next[C], *suf;
	int len, pos, cnt;
};

Node nodes[SZ];
int sz;

template <typename It>
void process(It s, It t) {
	sz = 2;
	nodes[0].len = -1, nodes[0].suf = nodes;
	nodes[1].len = 0, nodes[1].suf = nodes;
	Node *last = nodes + 1;
	int n = t - s;
	rep (i, n) (last = add_node(s, i, last))->cnt++;
	for (int i = sz - 1; i > 1; i--) nodes[i].suf->cnt += nodes[i].cnt;
}

private:
template <typename It>
Node *match(It s, int i, Node *last) {
	while (i - 1 - last->len < 0 || s[i - 1 - last->len] != s[i])
		last = last->suf;
	return last;
}

template <typename It>
Node *add_node(It s, int i, Node *last) {
	last = match(s, i, last);
	if (last->next[s[i]]) return last->next[s[i]];

	Node *cur = nodes + (sz++);
	cur->len = last->len + 2, cur->pos = i - cur->len + 1;
	last->next[s[i]] = cur;

	if (cur->len == 1) cur->suf = nodes + 1;
	else cur->suf = match(s, i, last->suf)->next[s[i]];
	return cur;
}
};

PalindromeTree<N> pal_tree;

int np;
using PalNode = PalindromeTree<N>::Node;
PalNode *pals[N];

bool pal_cmp(PalNode* pa, PalNode* pb) {
	int pos_a = pa->pos, len_a = pa->len, ord_a = sa.ord[pos_a];
	int pos_b = pb->pos, len_b = pb->len, ord_b = sa.ord[pos_b];
	int common = n - pos_a;
	lcp_tree.rq(query)(min(ord_a, ord_b), max(ord_a, ord_b), common);
	if (len_a > common && len_b > common)
		return sa.ord[pos_a + common] < sa.ord[pos_b + common];
	if (len_a > common) return false;
	if (len_b > common) return true;
	return len_a < len_b;
}

void sort_pals() {
	np = pal_tree.sz - 2;
	rep (i, np) pals[i] = pal_tree.nodes + i + 2;
	sort(pals, pals + np, pal_cmp);
}

map<ll, ll> ans;

void output() {
	rep (i, nq) ans[qs[i]] = -1;
	PalNode **pal = pals;
	ll tot = 0;
	for (auto & ps : ans) {
		ll q = ps.fst;
		while (pal < pals + np && q >= tot + (*pal)->cnt)
			tot += (*(pal++))->cnt;
		if (pal == pals + np) break;
		ps.snd = f((*pal)->pos, (*pal)->pos + (*pal)->len);
	}
	rep (i, nq) printf("%lld\n", ans[qs[i]]);
}

int main() {
	scanf("%d%d%s", &n, &nq, s);
	rep (i, nq) {
		scanf("%lld", qs + i);
		qs[i]--;
	}
	make_f();
	rep (i, n) s[i] -= 'a';
	sa.process(s, s + n);
	lcp_tree.init(n, sa.lcp);
	pal_tree.process(s, s + n);
	sort_pals();
	output();
	return 0;
}
