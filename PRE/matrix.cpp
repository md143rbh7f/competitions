/*
 * This library implements some matrix algorithms which are templatized for
 * different types of containers (vector<vector<double>> for real-valued
 * matrices, vector<vector<int>> for integer matrices modulo N, etc...).
 */

/*
 * Matrix exponentiation
 */

// Matrix exponentiation on Z_N
vector<vll> id(int n)
{
	vector<vll> a(n, vll(n));
	rep(i, n) a[i][i] = 1;
	return a;
}

vector<vll> operator*(vector<vll> a, vector<vll> b)
{
	int n = a.size(), p = b.size(), m = b[0].size();
	vector<vll> c(n, vll(m));
	rep(i, n) rep(j, m) rep(k, p)
		c[i][j] = M(c[i][j] + M(a[i][k] * b[k][j]));
	return c;
}

vector<vll> operator^(vector<vll> a, ll b)
{
	if(!b) return id(a.size());
	vector<vll> next = (a * a)^(b / 2);
	return b % 2 ? next * a : next;
}


/*
 * Gaussian elimination
 */

// Gaussian elimination on R
bool zero(double x) { return abs(x) <= EPS; }
void normalise(vd & v, int j)
{
	double x = v[j];
	range(k, j, v.size()) v[k] /= x;
}
void zero_out(vd & v, vd & u, int j)
{
	if(zero(u[j])) return;
	double r = u[j] / v[j];
	range(k, j, v.size()) u[k] -= r * v[k];
}

// Gaussian elimination on Z_N
// Need to define inv()
// Be careful with overflow
inline bool zero(int x) { return !x; }
void normalise(vi & v, int j)
{
	int x = inv(v[j]);
	range(k, j, v.size()) v[k] = M(v[k] * x);
}
void zero_out(vi & v, vi & u, int j)
{
	if(zero(u[j])) return;
	int r = M(u[j] * inv(v[j]));
	range(k, j, v.size()) u[k] = M(u[k] - M(r * v[k]) + MOD);
}

// Gaussian elimination on Z_2
inline bool zero(bool x) { return !x; }
template <size_t SZ>
void normalise(bitset<SZ> & v, int j) {}
template <size_t SZ>
void zero_out(bitset<SZ> & v, bitset<SZ> & u, int j) { if(u[j]) u ^= v; }

/*
 * Uses Gaussian elimination to put a matrix in reduced row-echelon form.
 * If m is provided, will not reduce past column m.
 * Returns rank of reduced matrix.
 */
template <typename T>
int rref(vector<T> & a, int m = 0)
{
	int n = a.size(), r = 0;
	if(!m) m = a[0].size();
	rep(j, m)
	{
		bool found = false;
		range(i, r, n) if(!zero(a[i][j]))
		{
			found = true;
			swap(a[r], a[i]);
			break;
		}
		if(!found) continue;
		normalise(a[r], j);
		rep(i, n) if(!zero(a[i][j]) && i != r) zero_out(a[r], a[i], j);
		r++;
	}
	return r;
}
