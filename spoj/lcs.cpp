#include <algorithm>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

template <int SZ, int C>
struct SuffixAutomaton  {
struct Node {
	Node *next[C], *suf;
	int len;
};

Node nodes[2 * SZ], *last;
int sz;

template <typename It>
void process(It s, It t) {
	sz = 1;
	nodes[0].len = 0, nodes[0].suf = nullptr;
	last = nodes;
	while (s != t) last = add_node(*(s++), last);
}

private:
template <typename T>
Node * add_node(T c, Node *par) {
	Node *cur = nodes + (sz++);
	cur->len = par->len + 1;
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

constexpr int N = 250005, C = 26;

SuffixAutomaton<N, C> sa;
char buf[N];

int main() {
	char *s;

	scanf("%s", buf);
	for (s = buf; *s; s++) *s -= 'a';
	sa.process(buf, s);

	scanf("%s", buf);
	int ans = 0, l = 0;
	SuffixAutomaton<N, C>::Node *cur = sa.nodes;
	for (s = buf; *s; s++) {
		char c = *s - 'a';
		while (cur != sa.nodes && !cur->next[c]) l = (cur = cur->suf)->len;
		if (cur->next[c]) cur = cur->next[c], ans = max(ans, ++l);
	}
	printf("%d\n", ans);
	return 0;
}
