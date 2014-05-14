#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define INF 100000001

template <typename T>
struct Point
{
T x, y;
inline Point<T> & operator-=(const Point<T> & o) { x -= o.x, y -= o.y; return *this; }
inline Point<T> operator-(const Point<T> & o) const { auto p = *this; return p -= o; }
inline bool operator<(const Point<T> & o) const { return x < o.x || (x == o.x && y < o.y); }
inline T r() const { return x * x + y * y; }
};

template <typename T>
struct by_y
{
inline bool operator()(const Point<T> & p, const Point<T> & q) const
{ return p.y < q.y || (p.y == q.y && p.x < q.x); }
};

template <typename T>
T closest(vector<Point<T>> & pt)
{
	if(pt.size() < 2) return 0;
	set<Point<T>, by_y<T>> u;
	T ans = INF;
	int lo = 0;
	for(auto & p : pt)
	{
		T lim = sqrt(ans) + 1;
		while(pt[lo].x < p.x - lim)
			u.erase(pt[lo++]);
		auto q = u.lower_bound({p.x - lim, p.y - lim});
		while(q != u.end() && q->y <= p.y + lim)
			ans = min(ans, (p - *(q++)).r());
		u.insert(p);
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<Point<ll>> pt;
	ll tot = 0;
	rep(i, n)
	{
		int x;
		cin >> x;
		tot += x;
		pt.push_back({i, tot});
	}
	cout << closest(pt) << endl;
	return 0;
}
