/*
 * Constructs the Knuth-Morris-Pratt 'failure function' f[l] for a string s,
 * which denotes the longest prefix of s which is also a suffix of the first l
 * characters of s.
 */
template <typename T, typename U>
void kmp(T s, T t, U f) {
	int n = t - s;
	f[0] = f[1] = 0;
	range (i, 1, n) {
		int &j = f[i + 1] = f[i];
		while (j > 0 && s[i] != s[j]) j = f[j];
		if (s[i] == s[j]) j++;
	}
}

/*
 * Given two strings and the KMP failure function for the second string,
 * computes the index where the second string occurs in the first string (or -1
 * if there is no match).
 */
template <typename T, typename U, typename V>
int find_match(T s, T t, U u, U v, V f) {
	int n = t - s, m = v - u, j = 0;
	rep (i, n) {
		while (j > 0 && s[i] != u[j]) j = f[j];
		if (s[i] == u[j]) j++;
		if (j == m) return i - m;
	}
	return -1;
}
