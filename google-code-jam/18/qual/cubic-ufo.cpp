#include <cmath>
#include <cstdio>

using namespace std;

using ld = long double;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr ld PI = acos((ld) -1), c = sqrtl(2) / 4;

void work() {
	ld a;
	scanf("%Lf", &a);
	ld q = acos(a / sqrtl(3)) - acos(1 / sqrtl(3));
	printf("%.9Lf %.9Lf %0.9Lf\n", 0.25 * (1 + cos(q)), -c * sin(q), 0.25 * (1 - cos(q)));
	printf("%.9Lf %.9Lf %0.9Lf\n", c * sin(q), 0.5 * cos(q), -c * sin(q));
	printf("%.9Lf %.9Lf %0.9Lf\n", 0.25 * (1 - cos(q)), c * sin(q), 0.25 * (1 + cos(q)));
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) {
		printf("Case #%d:\n", i + 1);
		work();
	}
	return 0;
}
