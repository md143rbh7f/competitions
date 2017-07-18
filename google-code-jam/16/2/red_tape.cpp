#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)
#define acc(f,x,y) x=f(x,y)

#define N 205

int n, k;
double p[N], q[2][N];

double prob(int m) {
	clr0(q);
	q[0][0] = 1;
	double * cur = q[0], * nxt = q[1];
	rep(i, k) {
		double r = i < m ? p[i] : p[i + n - k];
		rep(j, i + 2) nxt[j] = (j ? r * cur[j - 1] : 0) + (1 - r) * cur[j];
		swap(cur, nxt);
	}
	return cur[k / 2];
}

double work() {
	scanf("%d%d", &n, &k);
	rep(i, n) scanf("%lf", p + i);
	sort(p, p + n);
	double ans = 0;
	rep(m, k + 1) acc(max, ans, prob(m));
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	rep(i, T) printf("Case #%d: %.7lf\n", i + 1, work());
	return 0;
}
