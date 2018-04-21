#include <cstdio>
#include <cstring>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

bool ok[3][3];

void work() {
	int n, m = 0, k = 0, x, y;
	scanf("%d", &n);
	clr0(ok);
	while (true) {
		printf("%d 2\n", 3 * m + 2);
		fflush(stdout);
		scanf("%d%d", &x, &y);
		if (x == 0 && y == 0) return;
		x -= 3 * m + 1, y--;
		if (!ok[x][y]) ok[x][y] = true, k++;
		if (k == 9) m++, k = 0, clr0(ok);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	rep (_, t) work();
	return 0;
}
