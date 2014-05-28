#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

#define N 55

vs g;
int n, m, l;
bool seen[N][N];

void rec(int i, int j)
{
	if(i >= 0 && i < n && j >= 0 && j < m && g[i][j] == 'X' && !seen[i][j])
	{
		seen[i][j] = true;
		rec(i, j - 1), rec(i, j + 1);
		range(k, i - l, i + l + 1) rec(k, j);
	}
}


struct ArcadeManao
{
	int shortestLadder(vs _g, int r, int c)
	{
		g = _g, r--, c--, n = g.size(), m = g[0].size();
		int a = 0, b = n;
		while(a < b)
		{
			l = (a + b) / 2;
			clr0(seen);
			rec(n - 1, 0);
			if(seen[r][c]) b = l;
			else a = l + 1;
		}
		return a;
	}
};
