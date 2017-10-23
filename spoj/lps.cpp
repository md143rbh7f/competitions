#include <algorithm>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 100005;

template <size_t SZ, typename T=char, size_t C=26>
struct PalindromeTree  {
struct Node {
	Node * next[C], * suf;
	int len;
};

Node nodes[SZ];
int sz;

void process(T * s, int n) {
	sz = 2;
	nodes[0].len = -1, nodes[0].suf = nodes;
	nodes[1].len = 0, nodes[1].suf = nodes;
	Node * last = nodes + 1;
	rep (i, n) last = add_node(s, i, last);
}

private:
Node * match(T * s, int i, Node * last) {
	while (i - 1 - last->len < 0 || s[i - 1 - last->len] != s[i])
		last = last->suf;
	return last;
}

Node * add_node(T * s, int i, Node * last) {
	last = match(s, i, last);
	if (last->next[s[i]]) return last->next[s[i]];

	Node * cur = nodes + (sz++);
	cur->len = last->len + 2;
	last->next[s[i]] = cur;

	if (cur->len == 1) cur->suf = nodes + 1;
	else cur->suf = match(s, i, last->suf)->next[s[i]];
	return cur;
}
};

PalindromeTree<N> tree;
char s[N];

int main() {
	int n, ans = 0;
	scanf("%d%s", &n, s);
	rep (i, n) s[i] -= 'a';
	tree.process(s, n);
	rep (i, tree.sz) ans = max(ans, tree.nodes[i].len);
	printf("%d\n", ans);
	return 0;
}
