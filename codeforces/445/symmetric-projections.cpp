#include <algorithm>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define fst first
#define snd second

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
template <typename T> inline Point<T> operator-(Point<T> a) { return (T) -1 * a; }

constexpr int N = 2005;

Point<ll> pts[N];

bool symmetric(Point<ll> * p0, Point<ll> * p1, Point<ll> & l) {
	map<ll, int> proj;
	range (pt, p0, p1) {
		ll d = *pt % l;
		if (d > 0) proj[d]++;
		else if (d < 0) proj[-d]--;
	}
	for (auto & p : proj) if (p.snd) return false;
	return true;
}

int work() {
	int n;
	scanf("%d", &n);

	Point<ll> ctr {0, 0};
	rep (i, n) {
		scanf("%lld%lld", &pts[i].x, &pts[i].y);
		ctr += pts[i];
	}

	set<Point<ll>> mirror;
	rep (i, n) {
		pts[i] = (ll) n * pts[i] - ctr;
		if (!mirror.erase(-pts[i])) mirror.insert(pts[i]);
	}

	n = 0;
	for (auto & pt : mirror) pts[n++] = pt;
	if (n < 2) return -1;

	int ans = 0;
	set<Point<ll>> ls;
	rep (i, n) {
		Point<ll> l = pts[0] + pts[i];
		ll g = __gcd(abs(l.x), abs(l.y)) * (Point<ll>{0, 0} < l ? 1 : -1);
		l.x /= g, l.y /= g;
		if (ls.count(l)) continue;
		ls.insert(l);
		ans += symmetric(pts, pts + n, l);
	}
	return ans;
}

int main() {
	printf("%d\n", work());
	return 0;
}
