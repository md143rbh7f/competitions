#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

#define MOD 1000000009
#define N 300005

int s[N], fib[N];

struct SegmentNode
{
	SegmentNode * l, * r;
	int a, b, sum, x1, x0;

	inline void add(int y1, int y0)
	{
		x1 = M(x1 + y1), x0 = M(x0 + y0);
	}

	inline int value()
	{
		return M(sum + M(M(M((ll) fib[b - a + 2] * x1) + M((ll) fib[b - a + 1] * x0)) + M(MOD - M(x1 + x0))));
	}

	inline void push()
	{
		l->add(x1, x0);
		int d = r->a - a;
		r->add(
			M(M((ll) fib[d + 1] * x1) + M((ll) fib[d] * x0)),
			M(M((ll) fib[d] * x1) + M((ll) fib[d - 1] * x0))
		);
		x1 = x0 = 0;
	}

	void update(int i, int j)
	{
		if(j <= a || b <= i) return;
		if(i <= a && b <= j)
		{
			add(fib[a - i + 1], fib[a - i]);
			return;
		}
		push();
		l->update(i, j), r->update(i, j);
		sum = M(l->value() + r->value());
	}

	int query(int i, int j)
	{
		if(j <= a || b <= i) return 0;
		if(i <= a && b <= j) return value();
		push();
		int ans = M(l->query(i, j) + r->query(i, j));
		sum = M(l->value() + r->value());
		return ans;
	}

	SegmentNode * init(int i, int j)
	{
		a = i, b = j;
		if(b - a == 1)
		{
			sum = s[i];
			return this + 1;
		}
		int c = (a + b) / 2;
		auto ans = (r = (l = this + 1)->init(a, c))->init(c, b);
		sum = M(l->sum + r->sum);
		return ans;
	}
};

SegmentNode buf[2*N], * tree = buf;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	fib[1] = 1;
	range(i, 2, N) fib[i] = M(fib[i - 1] + fib[i - 2]);

	rep(i, n) scanf("%d", s + i);
	tree->init(0, n);

	while(m--)
	{
		int t, i, j;
		scanf("%d%d%d", &t, &i, &j);
		i--;
		if(t == 1) tree->update(i, j);
		else printf("%d\n", tree->query(i, j));
	}

	return 0;
}
