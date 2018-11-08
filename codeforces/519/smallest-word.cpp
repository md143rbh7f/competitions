#include <cstdio>

using namespace std;

constexpr int N = 1005;

char s[N];

int main() {
	scanf("%s", s);
	for (int i = 1;; i++) {
		printf(" %d", (s[i] ? s[i] : 'b') != s[i - 1]);
		if (!s[i]) break;
	}
	return 0;
}
