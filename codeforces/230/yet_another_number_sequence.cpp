#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

#define MOD 1000000007
#define N 42

int choose[N][N];

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

int main()
{
	rep(n, N) choose[n][0] = 1;
	range(n, 1, N) range(k, 1, n + 1)
		choose[n][k] = M(choose[n-1][k] + choose[n-1][k-1]);

	ll t;
	int p;
	cin >> t >> p;

	int s = 2 * p + 3;
	vector<vll> m(s, vll(s)), x(s, vll(1));
	rep(i, p + 1) rep(j, i + 1)
		m[i][j] = m[i][j + p + 1] = m[i + p + 1][j] = choose[i][j];
	m[s-1][p] = m[s-1][s-1] = 1;
	rep(i, p + 1) x[i][0] = x[i + p + 1][0] = 1;

	cout << ((m ^ t) * x)[s-1][0] << endl;
	return 0;
}
