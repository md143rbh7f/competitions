#include <algorithm>
#include <cstring>
#include <list>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

#define N 1005
#define INF 123456789

template <typename T>
struct Point
{
T x, y;
inline Point<T> & operator-=(const Point<T> & o) { x -= o.x, y -= o.y; return *this; }
inline Point<T> operator-(const Point<T> & o) const { auto p = *this; return p -= o; }
inline T operator%(const Point<T> & o) const { return x * o.y - y * o.x; }
};

template <typename T>
inline int sgn(T x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }

template <typename T>
struct Line
{
	int id, red, blue;
	Point<T> a, b;
	inline bool _intersects(const Line<T> & o) const { return sgn((o.a - a) % (b - a)) * sgn((o.b - a) % (b - a)) <= 0; }
	inline bool intersects(const Line<T> & o) const { return _intersects(o) && o._intersects(*this); }
};

struct Edge
{
	int j, c, f;
	Edge * r;
};

vector<Edge*> g[N];
int n;

void add_edge(int i, int j, int c = 1)
{
	Edge* e = new Edge{j, c, 0, 0}, *f = new Edge{i, 0, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

Edge* pre[N];

int bfs(int s, int t)
{
	list<int> q;
	q.push_back(s);
	while(!q.empty())
	{
		int i = *q.begin();
		q.pop_front();
		for(auto e : g[i]) if(e->c > e->f && e->j != s && !pre[e->j])
			pre[e->j] = e, q.push_back(e->j);
	}
	if(!pre[t]) return 0;
	int f = INF;
	for(Edge* e = pre[t]; e; e = pre[e->r->j])
		f = min(f, e->c - e->f);
	for(Edge* e = pre[t]; e; e = pre[e->r->j])
		e->f += f, e->r->f -= f;
	return f;
}

int max_flow(int s, int t)
{
	for(clr0(pre); bfs(s, t); clr0(pre));
	int ans = 0;
	for(auto e : g[s]) ans += e->f;
	return ans;
}

struct SegmentDrawing
{
int maxScore(vi xs, vi ys, vi rs, vi bs)
{
	int m = xs.size(), k = 0, tot = 0;

	vector<Line<ll>> ls;
	rep(i, m) range(j, i + 1, m)
		ls.push_back({
			k++, rs[m * i + j], bs[m * i + j],
			{xs[i], ys[i]}, {xs[j], ys[j]}
		});

	n = 2 * k + 2;

	for(auto & s : ls)
	{
		tot += s.red + s.blue;
		add_edge(n - 2, s.id, s.red);
		add_edge(k + s.id, n - 1, s.blue);
		for(auto & t : ls) if(s.intersects(t))
			add_edge(s.id, k + t.id, INF);
	}

	return tot - max_flow(n - 2, n - 1);
}
};
