/*
 * A Fenwick tree is a data structure that allows one to quickly
 *
 *   1. Modify an element in a list.
 *
 *   2. Sum up all the elements in a subrange of the list.
 *
 * It guarantees O(log N) performance on either operation by cleverly using bit
 * operations and some number-theoretic tricks. For this reason, it is also
 * called a binary-indexed tree, or BIT. For more information, see here:
 * http://math-porn.tumblr.com/post/93129714459/range-queries-and-fenwick-trees
 *
 * Quick usage notes and caveats:
 *
 *   * Fenwick tree indices are 1-based.
 */

template <int SZ>
struct FenwickTree {
int y[SZ];

// x[i] += d
void add(int i, int d) {
	for (; i < SZ; i += i&(-i)) y[i] += d;
}

void add(int a, int b, int d) {
	add(a, d), add(b, -d);
}

// return x[1] + x[2] + ... + x[i]
int sum(int i) {
	int ans = 0;
	for (; i; i -= i&(-i)) ans += y[i];
	return ans;
}

int get(int i) {
	return sum(i) - sum(i - 1);
}

// find last i such that sum(i) < s
int find(int s) {
	int i, del = 1;
	for (i = SZ / 2; i; i /= 2) del *= 2;
	for (i = 0; del; del /= 2) if (i + del < SZ && y[i + del] < s)
		i += del, s -= y[i];
	return i;
}

void scale(int c) {
	for (int i = 1; i <= SZ; i++) y[i] *= c;
}
};
