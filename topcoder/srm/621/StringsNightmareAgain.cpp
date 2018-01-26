#include <vector>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 100005;

template <int SZ, int C>
struct SuffixAutomaton  {
struct Node {
Node *next[C], *suf;
int len, fst, lst;
bool seen;

ll rec() {
	if (seen) return 0;
	seen = true;
	ll ans = 0;
	for (auto v : next) if (v) {
		ans += v->rec();
		lst = max(lst, v->lst - 1);
	}
	if (suf && lst - fst > suf->len) ans += min(lst - fst, len) - suf->len;
	return ans;
}
};

Node nodes[2 * SZ], *last;
int sz;

template <typename It>
ll process(It s, It t) {
	sz = 1;
	nodes[0].len = 0, nodes[0].suf = nullptr;
	last = nodes;
	while (s != t) last = add_node(*(s++), last);
	for (Node *v = last; v; v = v->suf) v->lst = last->lst;
	return nodes->rec();
}

private:
template <typename T>
Node * add_node(T c, Node *par) {
	Node *cur = nodes + (sz++);
	cur->lst = cur->fst = cur->len = par->len + 1;
	for (; par && !par->next[c]; par = par->suf) par->next[c] = cur;
	if (par) {
		Node *suf = par->next[c];
		if (suf->len > par->len + 1) {
			Node *clone = nodes + (sz++);
			*clone = *suf;
			clone->len = par->len + 1;
			for (; par && par->next[c] == suf; par = par->suf)
				par->next[c] = clone;
			suf->suf = cur->suf = clone;
		} else cur->suf = suf;
	} else cur->suf = nodes;
	return cur;
}
};


bool s[N];
SuffixAutomaton<N, 2> sa;

struct StringsNightmareAgain {
ll UniqueSubstrings(int a, int b, int c, int d, int n) {
	rep (i, a) s[b = ((ll) b * c + d) % n] = 1;
	return sa.process(s, s + n);
}
};
