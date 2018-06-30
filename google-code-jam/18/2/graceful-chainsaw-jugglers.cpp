#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)

constexpr int N = 501, S = 35;

int ans[N][N];

void pre() {
	clr1(ans);
	ans[0][0] = 0;
	rep (i, S) rep (j, S)
	for (int x = N - 1; x >= i; x--) for (int y = N - 1; y >= j; y--)
	if (ans[x - i][y - j] != -1)
		ans[x][y] = max(ans[x][y], ans[x - i][y - j] + 1);
}

int main() {
	pre();
	int t;
	scanf("%d", &t);
	rep (i, t) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d\n", i + 1, ans[a][b] - 1);
	}
	return 0;
}
