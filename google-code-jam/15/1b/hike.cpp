#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define acc(f,x,y) x=f(x,y)

struct Hiker
{
	double t;
	int dy, dt;

	bool operator<(const Hiker & o) const
	{
		if(t != o.t) return t < o.t;
		if(dy != o.dy) return o.dy < dy;
		return dt < o.dt;
	}
};

int work()
{
	int n;
	scanf("%d\n", &n);

	set<Hiker> hs;
	int y = 0;
	rep(i, n)
	{
		int x0, m, t;
		scanf("%d%d%d", &x0, &m, &t);
		rep(j, m) hs.insert({(1 - x0 / 360.0) * (t + j), -1, t + j});
		y += m;
	}

	int t_max = 3 * y, best = y;
	rep(t, t_max)
	{
		Hiker h = *hs.begin();
		hs.erase(hs.begin());
		y += h.dy;
		acc(min, best, y);
		hs.insert({h.t + h.dt, 1, h.dt});
	}

	return best;
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, t) printf("Case #%d: %d\n", i + 1, work());
	return 0;
}
