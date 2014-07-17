#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define EPS 1e-9

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

template <typename T>
void inv(vector<T> & a)
{
	int n = a.size();
	vector<T> b(a);
	rep(i, n)
	{
		b[i].resize(2 * n);
		b[i][n + i] = 1;
	}
	rref(b, n);
	rep(i, n) rep(j, n)
		a[i][j] = b[i][n + j];
}

vector<vd> id(int n)
{
	vector<vd> a(n, vd(n));
	rep(i, n) a[i][i] = 1;
	return a;
}

vector<vd> operator*(vector<vd> a, vector<vd> b)
{
	int n = a.size(), p = b.size(), m = b[0].size();
	vector<vd> c(n, vd(m));
	rep(i, n) rep(j, m) rep(k, p)
		c[i][j] += a[i][k] * b[k][j];
	return c;
}

vector<vd> operator^(vector<vd> a, ll b)
{
	if(!b) return id(a.size());
	vector<vd> next = (a * a)^(b / 2);
	return b % 2 ? next * a : next;
}

#define N 505

int tot[N];
bool bad[N];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	vi trap;
	rep(i, n)
	{
		scanf("%d", bad + i);
		if(bad[i]) trap.push_back(i);
	}
	int p = trap.size();

	vector<vd> cnt(n, vd(n));
	rep(i, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		tot[u]++, cnt[u][v]++;
		tot[v]++, cnt[v][u]++;
	}

	vector<vd> next(n, vd(n));
	rep(i, n)
	{
		rep(j, n) if(!bad[j]) next[i][j] = -cnt[i][j];
		next[i][i] = tot[i];
	}
	inv(next);
	next = next * cnt;

	vector<vd> a(p, vd(p)), x(1, vd(p));
	rep(i, p)
	{
		x[0][i] = next[0][trap[i]];
		rep(j, p) a[i][j] = next[trap[i]][trap[j]];
	}

	printf("%.6lf", (x * (a^(k - 2)))[0][p - 1]);

	return 0;
}
