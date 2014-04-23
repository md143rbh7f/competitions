#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 50
#define M 1000 + N

int m, deg[N], ans[M];
vector<vi> g[N];

void edge(int i, int j)
{
	g[i].push_back({m, 1, j}), deg[i]++;
	g[j].push_back({m, 2, i}), deg[j]++;
	m++;
}

void dfs(int i)
{
	for(auto & e : g[i]) if(!ans[e[0]])
	{
		ans[e[0]] = e[1];
		dfs(e[2]);
	}
}

struct PieOrDolphin
{
	vi Distribute(vi a, vi b)
	{
		int k = a.size(), I = -1;
		rep(j, k) edge(a[j], b[j]);
		rep(i, N) if(deg[i] % 2)
		{
			if(I != -1) edge(i, I), I = -1;
			else I = i;
		}
		rep(i, N) dfs(i);
		return vi(ans, ans + k);
	}
};
