#include <cstdio>
#include <cstring>

using namespace std;

constexpr int N = 205;

#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

int cnt[N];
bool sold[N];

void work() {
	int n, d, x;
	scanf("%d", &n);
	clr0(cnt), clr0(sold);
	while (n--) {
		int best = -1;
		scanf("%d", &d);
		while (d--) {
			scanf("%d", &x);
			if (sold[x]) continue;
			if (best == -1 || cnt[x] < cnt[best]) best = x;
			cnt[x]++;
		}
		sold[best] = true;
		printf("%d\n", best);
		fflush(stdout);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}
