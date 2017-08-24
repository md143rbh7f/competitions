#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)
#define acc(f,x,y) x=f(x,y)

constexpr int N = 55;
int n, k;
double u, ps[N], qs[N], buf[2][N];

double test(int a, int b, double target) {
	rep (i, n) {
		qs[i] = a <= i && i < b ? target : ps[i];
	}

	clr0(buf);
	double * cur = buf[0], * nxt = buf[1];
	cur[0] = 1;
    rep (i, n) {
		rep (j, n + 1)
			nxt[j] = qs[i] * (j ? cur[j - 1] : 0) + (1 - qs[i]) * cur[j];
		swap(cur, nxt);
	}

	return accumulate(cur + k, cur + n + 1, 0.0);
}

double work() {
	scanf("%d%d%lf", &n, &k, &u);
	rep (i, n)
		scanf("%lf", ps + i);
	sort(ps, ps + n);
	ps[n] = 1;
	
    double ans = 0;
	for (int m = n; m >= 0; m--) {
        rep (i, m) {
            double tot = 0;
            range (j, i + 1, m + 1) {
                tot += ps[j - 1];
                double target = min(1.0, (u + tot) / (j - i));
                if (ps[j - 1] <= target && target <= ps[j]) {
                    acc(max, ans, test(i, j, target));
                    break;
				}
			}
		}
        if (ps[m - 1] + u >= 1) {
            u -= 1 - ps[m - 1];
            ps[m - 1] = 1;
		} else break;
	}
		
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t)
		printf("Case #%d: %.7f\n", i + 1, work());
	return 0;
}
