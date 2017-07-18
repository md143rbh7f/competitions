import std.stdio;

enum N = 1000000;

int[N + 5] ans;
int[N + 5] q;
int qi, qj, cnt = N;

int rev(int x)
{
	int y = 0;
	while (x)
	{
		y = 10 * y + x % 10;
		x /= 10;
	}
	return y;
}

void push(int x, int y)
{
	if (ans[y] || y > N) return;
	ans[y] = ans[x] + 1;
	q[qj++] = y;
	cnt--;
}

int pop()
{
	return q[qi++];
}

void pre()
{
	push(0, 1);
	while (cnt)
	{
		int x = pop();
		push(x, x + 1);
		push(x, rev(x));
	}
}

void main() {
	pre();
	int t, n;
	readf("%d\n", &t);
	for (int i = 1; i <= t; i++) {
		readf("%d\n", &n);
		writeln("Case #", i, ": ", ans[n]);
	}
}
