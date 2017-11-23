#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int C = 128;

bool seen[C];
char pre[C], nxt[C];

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	rep (i, n) {
		char a = 0, b;
		while ((b = getchar()) != '\n') {
			if (a != 0) {
				char x = b;
				while (x && x != a) x = nxt[x];
				if (x || (nxt[a] && nxt[a] != b) || (pre[b] && pre[b] != a)) {
					printf("NO\n");
					return 0;
				}
				nxt[a] = b, pre[b] = a;
			}
			seen[b] = true, a = b;
		}
	}
	range (c, 'a', 'z' + 1) if (seen[c] && !pre[c])
	for (char x = c; x; x = nxt[x])
		putchar(x);
	putchar('\n');
	return 0;
}
