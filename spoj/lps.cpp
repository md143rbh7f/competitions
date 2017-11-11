#include <algorithm>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 100005;

template <int SZ>
struct Manacher {
int sz, len[2 * SZ];

template <typename It>
void process(It s, It t) {
	sz = 2 * (t - s) - 1;
	int r = 0;
	rep (i, sz) {
		if (i == r + len[r]) len[i] = 0;
		else len[i] = min(len[2 * r - i], r + len[r] - i);
		int x = i - len[i] - 1, y = i + len[i] + 1;
		while (x >= -1 && y <= sz && (x & 1 || s[x / 2] == s[y / 2]))
			len[i]++, x--, y++;
		if (i + len[i] > r + len[r]) r = i;
	}
}
};

Manacher<N> manacher;
char s[N];

int main() {
	int n, ans = 0;
	scanf("%d%s", &n, s);
	manacher.process(s, s + n);
	rep (i, manacher.sz) ans = max(ans, manacher.len[i]);
	printf("%d\n", ans);
	return 0;
}
