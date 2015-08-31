#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define N 55

vi g[N];

int dfs(int i)
{
	int ans = 0;
	for(auto j : g[i]) acc(max, ans, 1 + dfs(j));
	return ans;
}

struct WalkOverATree
{
int maxNodesVisited(vi p, int l)
{
	int n = p.size() + 1;
	rep(i, n - 1) g[p[i]].push_back(i + 1);
	int h = dfs(0);
	return min(min(n, l + 1), h + 1 + (l - h) / 2);
}
};
