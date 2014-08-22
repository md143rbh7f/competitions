template <int S>
struct SuffixArrayWorker
{
// Implementation of Kärkkäinen / Sanders algorithm for computing the suffix array in linear time.

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

// Computes suffix array for s[0, ... , n - 1] as ans.
// Note: It is required that s[n] = s[n + 1] = s[n + 2] = 0, and 1 <= s[i] < r otherwise.
void work(int * s, int * ans, int n, int r, int * buf = NULL)
{
	if(!buf) buf = _buf;

	int n0 = (n + 2) / 3, n2 = n / 3, nx = n0 + n2;
	int * a0 = alloc(buf, n0), * ax = alloc(buf, nx + 3);
	int * b0 = alloc(buf, n0), * bx = alloc(buf, nx);
	ax[nx] = ax[nx + 1] = ax[nx + 2] = 0;
 
	// sort suffixes that are 1 or 2 mod 3
	// (add dummy index in some cases)
	rep(i, n0) ax[i] = 3 * i + 1;
	rep(i, n2) ax[i + n0] = 3 * i + 2;
	radix_sort(ax, bx, s + 2, nx, r, buf);
	radix_sort(bx, ax, s + 1, nx, r, buf);
	radix_sort(ax, bx, s, nx, r, buf);

	// compute ord numbers for suffixes
	int ord = 0;
	auto c = tup(-1, -1, -1);
	range(i, bx, bx + nx)
	{
		auto d = tup(s[*i], s[*i + 1], s[*i + 2]);
		if(d != c) ord++, c = d;
		ax[*i / 3 + (*i % 3 == 2) * n0] = ord;
	}

	// if ords aren't unique, recurse and recompute ax/bx
	if(ord < nx)
	{
		work(ax, bx, nx, ord + 1, buf);
		rep(i, nx) ax[bx[i]] = i + 1, bx[i] = bx[i] < n0 ? 3 * bx[i] + 1 : 3 * (bx[i] - n0) + 2;
	}

	// sort mod 0 suffixes based on first character and mod 1 suffixes
	int j = 0;
	range(i, bx, bx + nx) if(*i % 3 == 1) a0[j++] = *i - 1;
	radix_sort(a0, b0, s, n0, r, buf);

	// merge sorted suffixes from b0 and bx
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

// Kasai's algorithm for computing the LCP from the suffix array
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
