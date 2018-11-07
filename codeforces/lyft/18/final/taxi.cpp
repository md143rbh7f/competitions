#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 200005, INF = 1000000005;

int xs[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	n += m;
	rep (i, n) scanf("%d", xs + i);
	xs[n] = 2 * INF;

	bool first = true;
	int l = -1, x = -INF, drive;
	rep (i, n + 1) {
		if (i < n) {
			scanf("%d", &drive);
			if (!drive) continue;
		}
		int r = l + 1;
		while (xs[r] - x <= xs[i] - xs[r]) r++;
		if (!first) printf("%d ", r - l - 1);
		first = false;
		l = r, x = xs[i];
	}
	printf("\n");

	return 0;
}
