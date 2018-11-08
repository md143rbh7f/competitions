#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 1005;

int xs[N];
bool ok[N];

int main() {
	int n, y = 0, z;
	scanf("%d", &n);
	rep (i, n) {
		scanf("%d", &z);
		xs[i] = z - y;
		y = z;
	}

	int cnt = 0;
	range (l, 1, n + 1) {
		ok[l] = true;
		range (i, l, n) if (xs[i] != xs[i % l]) {
			ok[l] = false;
			break;
		}
		cnt += ok[l];
	}

	printf("%d\n", cnt);
	range (l, 1, n + 1) if (ok[l]) printf("%d ", l);
	printf("\n");
	return 0;
}
