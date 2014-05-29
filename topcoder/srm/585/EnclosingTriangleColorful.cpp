#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)

template <typename T>
struct Point
{
T x, y;
inline Point<T> & operator-=(const Point<T> & o) { x -= o.x, y -= o.y; return *this; }
inline Point<T> operator-(const Point<T> & o) const { auto p = *this; return p -= o; }
inline T operator%(const Point<T> & o) const { return x * o.y - y * o.x; }
};

#define N 305

typedef vector<Point<int>> vp;
vp ps, qs[4];
bool ok[4][4][N][N];

struct EnclosingTriangleColorful
{
	int getNumber(int m, vi xs, vi ys)
	{
		rep(i, xs.size())
			ps.push_back({xs[i], ys[i]});

		range(i, 1, m)
			qs[0].push_back({i, 0});
		range(a, 1, 4) for(auto q : qs[a - 1])
			qs[a].push_back({m - q.y, q.x});
		m--;

		clr1(ok);
		rep(a, 4) rep(b, 4) if(a != b) rep(i, m) rep(j, m) for(auto & p : ps)
			ok[a][b][i][j] &= (qs[b][j] - qs[a][i]) % (p - qs[a][i]) >= 0;

		int ans = 0;
		rep(a, 4) rep(i, m) rep(j, m) rep(k, m)
			ans += ok[a][(a + 1) % 4][i][j] && ok[(a + 1) % 4][(a + 2) % 4][j][k] && ok[(a + 2) % 4][a][k][i];
		return ans;
	}
};
