/*
 * The union-find or disjoint-set-union data structure allows one to quickly do
 * the operations on a set of elements:
 *
 *   1. Query which subset an element belongs to.
 *
 *   2. Merge two subsets.
 *
 * Each subset is represented by a tree, and the par array maps each element to
 * its parent within the subset. For the root element, par stores the size of
 * the subset. Each subset may be uniquely indexed by its root element.
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
int par[SZ];

void clear() { clr1(par); }
UnionFind() { clear(); }

int find(int x) {
	int y = x;
	while (par[y] >= 0) y = par[y];
	while (par[x] >= 0) tie(x, par[x]) = tup(par[x], y);
	return y;
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (par[x] > par[y]) swap(x, y);
	par[x] += par[y], par[y] = x;
}
};
