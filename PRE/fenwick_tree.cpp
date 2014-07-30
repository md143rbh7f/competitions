/*
 * A Fenwick tree implementation. See
 * http://math-porn.tumblr.com/post/93129714459/range-queries-and-fenwick-trees
 * for more info.
 */

// REMEMBER: INDICES ARE 1-BASED.

struct FenwickTree
{
	int y[N];

	// x[i] += d
	void add(int i, int d)
	{
		for(; i < N; i += i&(-i)) y[i] += d;
	}

	void add(int a, int b, int d)
	{
		add(a, d), add(b, -d);
	}

	// return x[1] + x[2] + ... + x[i]
	int sum(int i)
	{
		int ans = 0;
		for(; i; i -= i&(-i)) ans += y[i];
		return ans;
	}

	int get(int i)
	{
		return sum(i) - sum(i - 1);
	}

	// find last i such that sum(i) < s
	int find(int s)
	{
		int i, del = 1;
		for(i = N / 2; i; i /= 2) del *= 2;
		for(i = 0; del; del /= 2) if(i + del < N && y[i + del] < s)
			i += del, s -= y[i];
		return i;
	}

	void scale(int c)
	{
		for(int i = 1; i <= N; i++) y[i] *= c;
	}
};
