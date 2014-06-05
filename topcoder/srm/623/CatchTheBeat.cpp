#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define N 500005

vector<pii> pts;
int a[N];

struct CatchTheBeat
{
int maxCatched(int n, int x, int y, int ax, int bx, int ay, int by, int mx, int my, int xo)
{
	rep(i, n)
	{
		int u = y + x - xo, v = y - x + xo;
		if(u >= 0 && v >= 0) pts.push_back({u, v});
		x = ((ll) x * ax + bx) % mx;
		y = ((ll) y * ay + by) % my;
	}
	sort(all(pts));

	int m = 0;
	for(auto pt : pts)
	{
		y = pt.second;
		int i = upper_bound(a, a + m, y) - a;
		a[i] = y;
		if(i == m) m++;
	}
	return m;
}
};
