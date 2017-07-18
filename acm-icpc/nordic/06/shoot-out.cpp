#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)

#define N 13

double p[N], win[1<<N][N][N], EPS = 1e-13;
// mask, person, shooter -> prob of surviving

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

struct Shot { int who, next; };

void solve()
{
	int n;
	scanf("%d", &n);
	rep(i, n) scanf("%lf", &p[i]), p[i] /= 100, win[1<<i][i][i] = 1;
	range(s, 1, 1<<n)
	{
		vi _;
		rep(i, n) if(s & (1 << i)) _.push_back(i);
		int m = _.size();
		if(m == 1) continue;

		vd best(m);
		vector<Shot> shots[m];
		rep(i, m) rep(j, m) if(i != j)
		{
			int k = (i + 1) % m;
			if(k == j) k = (k + 1) % m;
			double prob = win[s ^ (1 << _[j])][_[i]][_[k]];
			if(prob > best[i] + EPS) shots[i].clear(), best[i] = prob;
			if(zero(prob - best[i])) shots[i].push_back({j, k});
		}

		rep(i, m)
		{
			vector<vd> a(m, vd(m + 1));
			rep(j, m)
			{
				a[j][j] = 1, a[j][(j + 1) % m] = p[_[j]] - 1;
				for(auto & shot : shots[j])
					a[j][m] += win[s ^ (1 << _[shot.who])][_[i]][_[shot.next]];
				a[j][m] *= p[_[j]] / shots[j].size();
			}
			rref(a);
			rep(j, m) win[s][_[i]][_[j]] = a[j][m];
		}
	}
	rep(i, n) printf("%0.2f ", 100 * win[(1<<n)-1][i][0]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) solve(), clr(win);
	return 0;
}
