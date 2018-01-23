/*
 * The union-find or disjoint-set-union data structure allows one to quickly do
 * the operations on a set of elements:
 *
 *   1. Query which subset an element belongs to.
 *
 *   2. Merge two subsets.
 *
 * Each subset is represented by a tree, and the p array maps each element to
 * its parent within the subset. For the root element, p stores the size of its
 * subset. Each subset may be uniquely indexed by its root element.
 *
 * The merging and querying operations exploit this tree structure and also
 * simultaneously compress the trees for better performance. The amortised
 * runtime of an operation is the inverse Ackermann function, which is
 * practically constant for most reasonable set sizes.
 *
 * The code here is heavily based on Bruce Merry's implementation.
 */

template <int SZ>
struct UnionFind {
int p[SZ];

UnionFind() { clr1(p); }

int find(int x) {
	int y = x;
	while (p[y] >= 0) y = p[y];
	while (p[x] >= 0) tie(x, p[x]) = tup(p[x], y);
	return y;
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (p[x] > p[y]) swap(x, y);
	p[x] += p[y], p[y] = x;
}
};
