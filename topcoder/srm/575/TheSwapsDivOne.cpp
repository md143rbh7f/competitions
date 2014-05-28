#include <string>
#include <vector>

using namespace std;

typedef vector<double> vd;
typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define D 10
#define N 2222

int x[N], cnt[D];
double expect[D];

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
	rep(i, n) rep(j, m) rep(k, p) c[i][j] += a[i][k] * b[k][j];
	return c;
}

vector<vd> operator^(vector<vd> a, int b)
{
	if(!b) return id(a.size());
	vector<vd> next = (a * a)^(b / 2);
	return b % 2 ? next * a : next;
}

struct TheSwapsDivOne
{
	double find(vs seq, int k)
	{
		int n = 0;
		for(auto & s : seq) for(auto & c : s) x[n++] = c - '0';
		rep(i, n) cnt[x[i]]++;

		vector<vd> a(D, vd(D));
		rep(i, D) rep(j, D)
			a[i][j] = (2.0 * (cnt[j] - (i == j)) / (n - 1) + (i == j) * (n - 2)) / n;
		a = a ^ k;

		rep(i, D) rep(j, D) expect[i] += j * a[i][j];

		double ans = 0;
		rep(i, n) ans += expect[x[i]] * (i + 1) * (n - i) * 2 / (n + 1) / n;
		return ans;
	}
};
