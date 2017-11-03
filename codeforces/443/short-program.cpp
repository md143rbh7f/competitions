#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int B = 10;

char buf[2];

int apply(char op, int x, int y) {
	if (op == '&') return x & y;
	if (op == '|') return x | y;
	return x ^ y;
}

int main() {
	int n;
	scanf("%d", &n);

	int x, y = ((1 << B) - 1) << B;

	rep (i, n) {
		scanf("%s%d", buf, &x);
		y = apply(buf[0], x | (x << B), y);
	}

	int and_x = (1 << B) - 1, or_x = 0, xor_x = 0;
	rep (b, B) {
		int u = (y >> b) & 1, v = (y >> (b + B)) & 1;
		if (u == 0 && v == 0) and_x ^= 1 << b;
		else if (u == 1 && v == 1) or_x ^= 1 << b;
		else if (u == 1 && v == 0) xor_x ^= 1 << b;
	}


	printf("%d\n", 3);
	printf("& %d\n", and_x);
	printf("| %d\n", or_x);
	printf("^ %d\n", xor_x);

	return 0;
}
