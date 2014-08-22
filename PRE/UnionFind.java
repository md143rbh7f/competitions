/*
	Implementation of union-find or disjoint-set-union data structure.
	Based on Bruce Merry's implementation.
*/

class UnionFind
{
int[] par;

UnionFind(int n)
{
	par = new int[n];
	clear();
}

void clear() { Arrays.fill(par, -1); }

int find(int x)
{
	int y = x;
	while(par[y] >= 0) y = par[y];
	while(x != y)
	{
		int old = x;
		x = par[x];
		par[old] = y;
	}
	return y;
}

void merge(int x, int y)
{
	x = find(x); y = find(y);
	if(x == y) return;
	if(par[x] > par[y])
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
	par[x] += par[y];
	par[y] = x;
}
}
