/*
 * General segment tree implementation
 */

template <typename T, typename S>
struct SegmentNode
{
SegmentNode * l, * r;
int a, b;
T sum;
S lazy;

virtual void add(S);
virtual T plus(T, T), value();
virtual S zero();

void push()
{
	l->add(lazy), r->add(lazy);
	lazy = zero();
}

void update(int i, int j, S x)
{
	if(j <= a || b <= i) return;
	if(i <= a && b <= j)
	{
		add(x);
		return;
	}
	push();
	l->update(i, j, x), r->update(i, j, x);
	sum = plus(l->value(), r->value());
}

T query(int i, int j)
{
	if(j <= a || b <= i) return T();
	if(i <= a && b <= j) return value();
	push();
	T ans = plus(l->query(i, j), r->query(i, j));
	sum = plus(l->value(), r->value());
	return ans;
}

SegmentNode * init(int i, int j)
{
	a = i, b = j, l = r = nullptr;
	sum = T();
	lazy = zero();
	if(b - a == 1) return this + 1;
	int c = (a + b) / 2;
	return (r = (l = this + 1)->init(a, c))->init(c, b);
}
};


/*
 * Usage:
 */

#define N 100005

struct SumNode : public SegmentNode<ll, ll>
{
inline ll plus(ll x, ll y) { return x + y; }
inline void add(ll x) { lazy += x; }
inline ll value() { return sum + lazy * (b - a); }
inline ll zero() { return 0; }
};

SumNode buf[2*N], * tree = buf;

tree->init(0, N);
