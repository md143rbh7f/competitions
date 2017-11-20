#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

template <typename T>
struct Point {
T x, y;
inline Point & operator+=(const Point & o) { x += o.x, y += o.y; return *this; }
inline Point operator+(const Point & o) const { auto p = *this; return p += o; }
inline Point & operator-=(const Point & o) { x -= o.x, y -= o.y; return *this; }
inline Point operator-(const Point & o) const { auto p = *this; return p -= o; }
inline T operator*(const Point & o) { return x * o.x + y * o.y; }
inline T operator%(const Point & o) const { return x * o.y - y * o.x; }
inline bool operator==(const Point & o) const { return x == o.x && y == o.y; }
inline bool operator<(const Point & o) const { return x < o.x || (x == o.x && y < o.y); }
inline double r() const { return hypot(x, y); }
inline T q() const { return atan2(y, x); }
};
template <typename T> inline Point<T> operator*(T c, Point<T> a) { return {c * a.x, c * a.y}; }
template <typename T> inline Point<T> operator-(Point<T> a) { return -1 * a; }

template <typename It>
double closest(It p0, It p1) {
	if (p1 - p0 < 2) return 0;
	using P = typename decay<decltype(*p0)>::type;
	sort(p0, p1, [](const P & p, const P & q) {
		return p.y < q.y || (p.y == q.y && p.x < q.x);
	});
	double ans = (p0[1] - p0[0]).r();
	set<P> w;
	range (p, p0, p1) {
		while (p0->y < p->y - ans)
			w.erase(*(p0++));
		auto q = w.lower_bound(*p - P{ceil(ans), ceil(ans)});
		while (q != w.end() && q->x <= p->x + ans)
			ans = min(ans, (*p - *(q++)).r());
		w.insert(*p);
	}
	return ans;
}

constexpr int N = 100005;

Point<ll> pts[N];

int main() {
	int n, t, y = 0;
	scanf("%d", &n);
	rep (i, n) {
		scanf("%d", &t);
		y += t;
		pts[i] = {i, y};
	}
	printf("%lld\n", (ll) round(pow(closest(pts, pts + n), 2)));
	return 0;
}
