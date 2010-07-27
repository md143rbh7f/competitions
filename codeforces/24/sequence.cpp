#include <iostream>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 100000

long long n, j, mx, my, x[MAX], y[MAX];

int main()
{
	cin >> n >> j >> mx >> my;
	j %= 2*n;
	rep(i,n) cin >> x[i] >> y[i];
	rep(i,j) mx = 2*x[i%n]-mx, my = 2*y[i%n]-my;
	cout << mx << ' ' << my;
	return 0;
}
