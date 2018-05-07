#include <cstdio>
#include <cstring>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

constexpr int L = 15, C = 26;

int n, l;
char s[L];
bool cs[L][C];

struct Node { Node *e[C]; };

bool rec(Node *x, int i) {
	if (i == l) return !x;
	rep (c, C) if (cs[i][c] && rec(x ? x->e[c] : nullptr, i + 1)) {
		s[i] = c + 'A';
		return true;
	}
	return false;
}

char *work() {
	scanf("%d%d", &n, &l);

	clr0(cs);
	Node *trie = new Node{};
	rep (_, n) {
		scanf("%s", s);
		Node *x = trie;
		rep (i, l) {
			char &c = s[i];
			c -= 'A';
			cs[i][c] = true;
			if (!x->e[c]) x->e[c] = new Node{};
			x = x->e[c];
		}
	}

	s[0] = '-', s[1] = 0;
	rec(trie, 0);

	return s;
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) printf("Case #%d: %s\n", i + 1, work());
	return 0;
}
