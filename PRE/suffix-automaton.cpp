/*
 * A suffix automaton of a string S is the smallest automaton that accepts all
 * substrings of S and nothing else. The automaton is constructed in linear
 * time, and each node of the automaton represents an equivalence class of
 * substrings that share the same end positions.
 *
 * Nodes / equivalence classes have the following attributes:
 *
 *   1. next[c] is the equivalence class of strings formed by appending the
 *      character c.
 *
 *   2. Suffixes of a class of strings have at least as many end positions as
 *      the class itself. suf represents the smallest such class that has
 *      strictly more end positions.
 *
 *   3. len is the length of the longest string in the equivalence class.
 *
 * Additional properties that are commented out:
 *
 *   1. pos is the first end position in the class.
 *
 *   2. end denotes whether the class includes the end of the string.
 *
 *   3. exts ('extensions') is the reverse of the suffix links. If class u is
 *      the suffix of class v, then u.exts includes v.
 */

template <int SZ, int C>
struct SuffixAutomaton  {
struct Node {
	Node *next[C], *suf;
	int len;
	//int len, pos;
	//bool end;
	//vector<Node*> exts;
};

Node nodes[2 * SZ], *last;
int sz;

template <typename It>
void process(It s, It t) {
	sz = 1;
	nodes[0].len = 0, nodes[0].suf = nullptr;
	last = nodes;
	while (s != t) last = add_node(*(s++), last);
	//for (Node *cur = last; cur; cur = cur->suf) cur->end = true;
	//range (v, nodes + 1, nodes + sz) v->suf->exts.push_back(v);
}

private:
template <typename T>
Node * add_node(T c, Node *par) {
	Node *cur = nodes + (sz++);
	cur->len = par->len + 1;
	//cur->pos = cur->len = par->len + 1;
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
