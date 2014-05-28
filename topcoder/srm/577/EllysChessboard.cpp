#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)

#define N 15

bool f[N][N];
int mem[N][N][N][N];

int rec(int x0, int y0, int x1, int y1)
{
	if(x0 > x1 || y0 > y1) return 0;
	int & ans = mem[x0][y0][x1][y1];
	if(ans != -1) return ans;
	int a = rec(x0 + 1, y0, x1, y1);
	range(y, y0, y1 + 1) if(f[x0][y]) a += max(x1 - x0, max(y - y0, y1 - y));
	int b = rec(x0, y0, x1 - 1, y1);
	range(y, y0, y1 + 1) if(f[x1][y]) b += max(x1 - x0, max(y - y0, y1 - y));
	int c = rec(x0, y0 + 1, x1, y1);
	range(x, x0, x1 + 1) if(f[x][y0]) c += max(y1 - y0, max(x - x0, x1 - x));
	int d = rec(x0, y0, x1, y1 - 1);
	range(x, x0, x1 + 1) if(f[x][y1]) d += max(y1 - y0, max(x - x0, x1 - x));
	return ans = min(min(a, b), min(c, d));
}

struct EllysChessboard
{
	int minCost(vs board)
	{
		rep(i, 8) rep(j, 8) f[i + j][i - j + 7] = board[i][j] == '#';
		clr1(mem);
		return rec(0, 0, N - 1, N - 1);
	}
};
