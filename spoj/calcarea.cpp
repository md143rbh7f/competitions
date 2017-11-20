#include <cmath>
#include <cstdio>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
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
auto polygon_area(It p0, It p1) -> decltype(p0->x) {
	int n = p1 - p0;
	decltype(p0->x) ans = 0;
	rep (i, n) ans += p0[i] % p0[(i + 1) % n];
	return ans / 2;
}

constexpr int N = 10005;

Point<double> pts[N];

int main() {
	int n;
	scanf("%d", &n);
	rep (i, n) scanf("%lf%lf", &pts[i].x, &pts[i].y);
	printf("%lld\n", (ll) polygon_area(pts, pts + n));
	return 0;
}
