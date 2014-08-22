#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)
#define tup make_tuple

template <int S>
struct SuffixArrayWorker
{
int _buf[7 * S + 50];

inline int * alloc(int * (&buf), int sz)
{
	int * ans = buf;
	buf += sz;
	return ans;
}

void radix_sort(int * suf, int * ans, int * s, int n, int r, int * c)
{
	rep(i, r) c[i] = 0;
	rep(i, n) c[s[suf[i]]]++;
	int t = 0;
	rep(i, r) tie(c[i], t) = tup(t, t + c[i]);
	rep(i, n) ans[c[s[suf[i]]]++] = suf[i];
}

void work(int * s, int * ans, int n, int r, int * buf = NULL)
{
	if(!buf) buf = _buf;

	int n0 = (n + 2) / 3, n2 = n / 3, nx = n0 + n2;
	int * a0 = alloc(buf, n0), * ax = alloc(buf, nx + 3);
	int * b0 = alloc(buf, n0), * bx = alloc(buf, nx);
	ax[nx] = ax[nx + 1] = ax[nx + 2] = 0;
 
	rep(i, n0) ax[i] = 3 * i + 1;
	rep(i, n2) ax[i + n0] = 3 * i + 2;
	radix_sort(ax, bx, s + 2, nx, r, buf);
	radix_sort(bx, ax, s + 1, nx, r, buf);
	radix_sort(ax, bx, s, nx, r, buf);

	int ord = 0;
	auto c = tup(-1, -1, -1);
	range(i, bx, bx + nx)
	{
		auto d = tup(s[*i], s[*i + 1], s[*i + 2]);
		if(d != c) ord++, c = d;
		ax[*i / 3 + (*i % 3 == 2) * n0] = ord;
	}

	if(ord < nx)
	{
		work(ax, bx, nx, ord + 1, buf);
		rep(i, nx) ax[bx[i]] = i + 1, bx[i] = bx[i] < n0 ? 3 * bx[i] + 1 : 3 * (bx[i] - n0) + 2;
	}

	int j = 0;
	range(i, bx, bx + nx) if(*i % 3 == 1) a0[j++] = *i - 1;
	radix_sort(a0, b0, s, n0, r, buf);

	int * u = b0, * v = bx + (n % 3 == 1);
	while(u < b0 + n0 && v < bx + nx)
		*ans++ = (
			*v % 3 == 1
			? tup(s[*u], ax[*u / 3]) < tup(s[*v], ax[*v / 3 + n0])
			: tup(s[*u], s[*u + 1], ax[*u / 3 + n0]) < tup(s[*v], s[*v + 1], ax[*v / 3 + 1])
		) ? *u++ : *v++;
	while(u < b0 + n0) *ans++ = *u++;
	while(v < bx + nx) *ans++ = *v++;
}

void work_lcp(int * s, int * suf, int * lcp, int n, int r, int * buf = NULL)
{
	if(!buf) buf = _buf;

	work(s, suf, n, r, buf);

	int * ord = buf, l = 0;
	rep(i, n) ord[suf[i]] = i;
	rep(i, n)
	{
		if(ord[i] < n - 1)
		{
			int j = suf[ord[i] + 1];
			while(i + l < n && j + l < n && s[i + l] == s[j + l]) l++;
			lcp[ord[i]] = l;
		}
		else l = 0;
		if(l) l--;
	}
}
};

#define N 300005
#define C 30
#define MOD 1000000007

struct State { int l; vi c; };

int s[N], suf[N], lcp[N], ans[N / 3];
char buf[N];
State _st[N], * st = _st;
SuffixArrayWorker<N> saw;

int get(int * s, int x)
{
	scanf("%s", buf);
	int n = 0;
	for(; buf[n]; n++) s[n] = buf[n] - 'a' + 1;
	s[n++] = 27 + x;
	return n;
}

int main()
{
	int n = 0, n0, n1, n2;
	n += n0 = get(s + n, 0), n += n1 = get(s + n, 1), n += n2 = get(s + n, 2);
	saw.work_lcp(s, suf, lcp, n, C);

	vi c(3);
	st->c = c;
	rep(i, n)
	{
		int x = suf[i], l = lcp[i];
		if(l > st->l) *(++st) = State {l, c};
		c[(x >= n0) + (x >= n0 + n1)]++;
		while(l < st->l)
		{
			int r = 1;
			rep(j, 3) r = M((ll) (c[j] - st->c[j]) * r);
			ans[st->l] = M(ans[st->l] + r);
			if(l > (st - 1)->l) st->l = l;
			else st--;
			ans[st->l] = M(ans[st->l] + MOD - r);
		}
	}

	int m = min(min(n0, n1), n2) - 1;
	for(int i = m - 1; i >= 0; i--) ans[i] = M(ans[i] + ans[i + 1]);
	range(i, 1, m + 1) printf("%d ", ans[i]);

	return 0;
}
