import std.stdio;

int work() {
	int a, b, k, ans = 0;
	readf("%d %d %d\n", &a, &b, &k);
	for (int i = 0; i < a; i++) for (int j = 0; j < b; j++)
		ans += (i & j) < k;
	return ans;
}

void main() {
	int n;
	readf("%d\n", &n);
	for (int i = 1; i <= n; i++)
		writeln("Case #", i, ": ", work());
}
