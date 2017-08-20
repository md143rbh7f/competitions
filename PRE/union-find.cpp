/*
	Implementation of union-find or disjoint-set-union data structure.
	Based on Bruce Merry's implementation.
*/

template <int S>
struct UnionFind
{
int par[S];

void clear() { clr1(par); }
UnionFind() { clear(); }

int find(int x)
{
	int y = x;
	while(par[y] >= 0) y = par[y];
	while(par[x] >= 0) tie(x, par[x]) = tup(par[x], y);
	return y;
}

void merge(int x, int y)
{
	x = find(x), y = find(y);
	if(x == y) return;
	if(par[x] > par[y]) swap(x, y);
	par[x] += par[y], par[y] = x;
}
};
