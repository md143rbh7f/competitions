/*
 * This class implements:
 *
 *   1. Kärkkäinen and Sanders' algorithm for computing the suffix array of a
 *      string in linear time.
 *
 *   2. Kasai's algorithm for computing the LCP array of the suffix array.
 *
 * Quick usage notes and gotchas:
 *
 *   * rec() requires that s[n] = s[n + 1] = s[n + 2] = 0, and otherwise
 *     1 <= s[i] < r. This makes the rest of the implementation easier.
 */

template <int SZ>
struct SuffixArray {
int *suf;
//int *suf, *ord, *lcp;

template <typename T>
void process(T s0, T s1) {
	int n = s1 - s0, r = 0, *buf = _buf, *s = alloc(buf, n + 3);
	suf = alloc(buf, n);
	for (int *t = s; s0 != s1; s0++, t++) r = max(r, (*t = *s0 + 1));
	s[n] = s[n + 1] = s[n + 2] = 0;
	rec(s, suf, n, r + 1, buf);

	/*
	// Compute LCP.
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
	*/
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
	// To simplify the implementation, we generate as many (1 mod 3) suffixes as
	// there are (0 mod 3) suffixes. This means that we will sometimes generate
	// an extra suffix that starts at the end of the string.
	int n0 = (n + 2) / 3, n2 = n / 3, nx = n0 + n2;
	int *ax = alloc(buf, nx + 3), *bx = alloc(buf, nx);
	ax[nx] = ax[nx + 1] = ax[nx + 2] = 0;

	// Iteratively radix sort (1 mod 3) and (2 mod 3) suffixes by their first
	// three characters.
	int *a1 = ax, *a2 = ax + n0;
	rep (i, n0) a1[i] = 3 * i + 1;
	rep (i, n2) a2[i] = 3 * i + 2;
	radix_sort(s + 2, ax, bx, nx, r, buf);
	radix_sort(s + 1, bx, ax, nx, r, buf);
	radix_sort(s, ax, bx, nx, r, buf);

	// Compute ordinal numbers for the sorted suffixes. Note that each ordinal
	// is a compressed representation of the first three characters of each
	// suffix.
	int ord = 0;
	auto x = tup(-1, -1, -1);
	range (b, bx, bx + nx) {
		auto y = tup(s[*b], s[*b + 1], s[*b + 2]);
		if (y > x) ord++, x = y;
		(*b % 3 == 1 ? a1 : a2)[*b / 3] = ord;
	}

	// If the ordinals are unique, then we are done. Otherwise, we must refine
	// them by recursively computing the suffix array for the array consisting
	// of the (1 mod 3) ordinals followed by the (2 mod 3) ordinals. Since each
	// ordinal is a compressed representation of three characters, a sequence of
	// (K mod 3) ordinals is a compressed representation of the entire string.
	// Thus, a suffix array of the ordinals is actually also a suffix array of
	// the original string, minus the (0 mod 3) suffixes.
	if (ord < nx) {
		rec(ax, bx, nx, ord + 1, buf);
		rep (i, nx) {
			ax[bx[i]] = i + 1;
			bx[i] = bx[i] < n0 ? 3 * bx[i] + 1 : 3 * (bx[i] - n0) + 2;
		}
	}

	// Radix sort (0 mod 3) suffixes based on their first characters and the
	// following (1 mod 3) ordinals.
	int *a0 = alloc(buf, n0), *b0 = alloc(buf, n0);
	ord = 0;
	range (b, bx, bx + nx) if (*b % 3 == 1) a0[ord++] = *b - 1;
	radix_sort(s, a0, b0, n0, r, buf);

	// Merge the list of sorted (0 mod 3) suffixes with the list of sorted
	// (1 mod 3) and (2 mod 3) suffixes by comparing some combination of
	// characters and ordinals. If we generated an extra (1 mod 3) suffix, we
	// should ignore it here.
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
