#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)
template <typename T> T read_next(istream & is = cin) { T x; is >> x; return x; }

typedef vector<vector<double>> matrix;

matrix I(int n)
{
	matrix ans(n, vector<double>(n));
	rep(i,n) ans[i][i] = 1;
	return ans;
}

matrix operator*(matrix a, matrix b)
{
	int n = a.size(), m = a[0].size(), p = b[0].size();
	matrix ans(n, vector<double>(p));
	rep(i,n) rep(j,p) rep(k,m) ans[i][j] += a[i][k] * b[k][j];
	return ans;
}

matrix operator^(matrix a, int t)
{
	int n = a.size();
	if(!t) return I(n);
	return (t % 2 ? a : I(n)) * ((a * a) ^ (t / 2));
}

ostream & operator<<(ostream & os, matrix a)
{
	for(auto & b : a)
	{
		for(auto & c : b) os << c << " ";
		os << endl;
	}
	return os;
}

void run()
{
	int n = read_next<int>(), m = read_next<int>(), t = read_next<int>();
	matrix x(n, vector<double>(1));
	rep(i,n) cin >> x[i][0];
	matrix a = I(n), e = I(n);
	while(m--)
	{
		int s = read_next<int>(), t = read_next<int>();
		double p = read_next<double>();
		a[t][s] = p, a[s][s] -= p;
		e[s][t] = e[t][s] = 1;
	}
	matrix y = e * (a ^ t) * x;
	double ans = y[0][0];
	rep(i,n) ans = min(ans, y[i][0]);
	printf("%.9lf\n", ans);
}

int main()
{
	for(int n = read_next<int>(); n--; ) run();
	return 0;
}
