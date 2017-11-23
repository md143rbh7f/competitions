#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 200005;

bool has[N];

int main() {
	int n, p, ans = 0;
	scanf("%d", &n);
	rep (i, n) {
		scanf("%d", &p);
		has[p] = true;
	}
	rep (i, n + 1) ans += !has[i];
	printf("%d\n", ans);
	return 0;
}
