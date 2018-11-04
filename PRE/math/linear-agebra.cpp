/*
 * This library implements some matrix algorithms which are templatized for
 * various fields (mainly Z_n / ints and R / doubles).
 */

/*
 * Matrix exponentiation
 */

template <typename T> using matrix = vector<vector<T>>;

template <typename T>
matrix<T> id(int n) {
	matrix<T> a(n, vector<T>(n));
	rep (i, n) a[i][i] = 1;
	return a;
}

template <typename T>
matrix<T> operator*(matrix<T> a, matrix<T> b) {
	int n = a.size(), p = b.size(), m = b[0].size();
	matrix<T> c(n, vector<T>(m));
	// This is for Z_n; obviously for doubles we don't need to mod.
	rep (i, n) rep (j, m) rep (k, p)
		c[i][j] = M(c[i][j] + M((ll) a[i][k] * b[k][j]));
	return c;
}

template <typename T>
matrix<T> operator^(matrix<T> a, ll b) {
	if (!b) return id<T>(a.size());
	matrix<T> next = (a * a)^(b / 2);
	return b % 2 ? next * a : next;
}


/*
 * Gaussian elimination
 */

// Gaussian elimination on R
bool zero(double x) { return abs(x) <= EPS; }
void normalise(vd & v, int j) {
	double x = v[j];
	range (k, j, v.size()) v[k] /= x;
}
void zero_out(vd & v, vd & u, int j) {
	if (zero(u[j])) return;
	double r = u[j] / v[j];
	range (k, j, v.size()) u[k] -= r * v[k];
}

// Gaussian elimination on Z_N
// Need to define inv()
// Be careful with overflow
// The code is defined for ints but works for longs also.
inline bool zero(int x) { return !x; }
void normalise(vi & v, int j) {
	int x = inv(v[j]);
	range (k, j, v.size()) v[k] = M((ll) v[k] * x);
}
void zero_out(vi & v, vi & u, int j) {
	if (zero(u[j])) return;
	int r = M((ll) u[j] * inv(v[j]));
	range (k, j, v.size()) u[k] = M(u[k] - M((ll) r * v[k]) + MOD);
}

// Gaussian elimination on Z_2
inline bool zero(bool x) { return !x; }
template <int SZ>
void normalise(bitset<SZ> & v, int j) {}
template <int SZ>
void zero_out(bitset<SZ> & v, bitset<SZ> & u, int j) { if (u[j]) u ^= v; }

/*
 * Uses Gaussian elimination to put a matrix in reduced row-echelon form.
 * If m is provided, will not reduce past column m.
 * Returns rank of reduced matrix.
 *
 * The reason we use vector<T> here instead of matrix<T> is because matrix<T>
 * doesn't work with bitsets.
 */
template <typename T>
int rref(vector<T> & a, int m = 0) {
	int n = a.size(), r = 0;
	if (!m) m = a[0].size();
	rep (j, m) {
		bool found = false;
		range (i, r, n) if (!zero(a[i][j])) {
			found = true;
			swap(a[r], a[i]);
			break;
		}
		if (!found) continue;
		normalise(a[r], j);
		rep (i, n) if (!zero(a[i][j]) && i != r) zero_out(a[r], a[i], j);
		r++;
	}
	return r;
}

/*
 * Invert a square matrix via Gaussian elimination.
 */
template <typename T>
void inv(vector<T> & a) {
	int n = a.size();
	vector<T> b(a);
	rep (i, n) {
		b[i].resize(2 * n);
		b[i][n + i] = 1;
	}
	rref(b, n);
	rep (i, n) rep (j, n)
		a[i][j] = b[i][n + j];
}
