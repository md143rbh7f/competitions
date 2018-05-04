/*
 * Palindromes
 */


/*
 * Manacher's algorithm computes for a given string the length of the longest
 * palindrome centered at each position in the string.
 *
 * The algorithm iterates from left to right, evaluating all possible center
 * positions for palindromes, while keeping track of the palindrome with the
 * rightmost character. When the algorithm evaluates a new palindrome center, it
 * first looks at the mirror image of this position reflected across the
 * rightmost palindrome. The palindrome length for the mirror image has already
 * been computed, and thus becomes a lower bound for the palindrome length of
 * the current position.
 *
 * Quick usage notes and gotchas:
 *
 *   * The length of the longest palindrome centered at s[i] is len[2 * i].
 *
 *   * Likewise, the length of the longest palindrome centered between s[i] and
 *     s[i + 1] is len[2 * i + 1].
 *
 */


template <int SZ>
struct Manacher {
int sz, len[2 * SZ];

template <typename It>
void process(It s, It t) {
	sz = 2 * (t - s) - 1;
	int r = 0;
	rep (i, sz) {
		if (i == r + len[r]) len[i] = 0;
		else len[i] = min(len[2 * r - i], r + len[r] - i);
		int x = i - len[i] - 1, y = i + len[i] + 1;
		while (x >= -1 && y <= sz && (x & 1 || s[x / 2] == s[y / 2]))
			len[i]++, x--, y++;
		if (i + len[i] > r + len[r]) r = i;
	}
}
};


/*
 * A string S of length N can contain no more than N distinct palindromes.
 *
 * Proof:
 * Let S' be the result of adding a new character to S. Let SUF be the set of
 * palindromes in S' but not in S, and let P be the longest palindrome in SUF.
 * Every palindrome in SUF must be itself be a suffix of P; and thus, it must
 * also be a prefix of P. But all of these prefixes are already wholly contained
 * within S, except for P itself. Thus, there can be at most one palindrome in
 * S' that is not also in S. The rest follows by induction.
 */


/*
 * A palindrome tree is a trie-like data structure that uses a node to represent
 * each distinct palindrome in a given string. By the above argument, there can
 * be no more than N nodes in the palindrome tree for a string of length N.
 *
 * A palindrome tree node has several different attributes:
 *
 *   next[c] := The palindrome formed by appending the character c to both
 *              sides of the current palindrome. Null if that palindrome does
 *              not exist in the string.
 *
 *   suf     := The longest proper suffix of the current palindrome that is also
 *              itself a palindrome.
 *
 *   len     := The length of the palindrome.
 *
 * The tree has two symbolic roots, representing palindromes of 'length' -1 and
 * 0. Palindromes of length 1 and 2 are formed by appending characters to both
 * sides of the symbolic roots.
 *
 * These attributes are the minimal attributes required to construct the rest of
 * the tree in linear time. We may additionally compute things like:
 *
 *   1. The first time a palindrome was encountered.
 *
 *   2. The parent node of each palindrome.
 *
 *   3. The number of times each palindrome was encountered.
 *
 * The palindrome tree was invented by Mikhail Rubinchik.
 *
 * Quick usage notes and gotchas:
 *
 *   * The characters in the input string must be in the range 0, 1, ..., C - 1.
 */

template <int SZ, int C=26>
struct PalindromeTree  {
struct Node {
	Node *next[C], *suf;
	int len;
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
	rep (i, n) last = add_node(s, i, last);
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
	cur->len = last->len + 2;
	last->next[s[i]] = cur;

	if (cur->len == 1) cur->suf = nodes + 1;
	else cur->suf = match(s, i, last->suf)->next[s[i]];
	return cur;
}
};
