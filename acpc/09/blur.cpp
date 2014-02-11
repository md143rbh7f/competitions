#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

typedef vector<double> vd;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

double EPS = 1e-13;

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

bool solve(int cnt)
{
	int h, w, d;
	scanf("%d%d%d", &w, &h, &d);
	if(!h) return false;
	if(cnt) printf("\n");

	#define _(x, y) ((x) * w + (y))

	int n = h * w;
	vector<vd> a(n, vd(n + 1));
	rep(i, h) rep(j, w)
	{
		scanf("%lf", &a[_(i, j)][n]);
		int cnt = 0;
		rep(ii, h) rep(jj, w) if(abs(i - ii) + abs(j - jj) <= d)
			cnt++, a[_(i, j)][_(ii, jj)] = 1;
		a[_(i, j)][n] *= cnt;
	}
	rref(a);
	rep(i, h)
	{
		rep(j, w) printf("%8.2lf", a[_(i, j)][n]);
		printf("\n");
	}

	return true;
}

int main()
{
	for(int i = 0; solve(i); i++);
	return 0;
}
