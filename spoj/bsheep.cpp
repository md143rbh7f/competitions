#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;

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
inline bool operator<(const Point & o) const { return y < o.y || (y == o.y && x < o.x); }
inline double r() const { return hypot(x, y); }
inline T q() const { return atan2(y, x); }
};
template <typename T> inline Point<T> operator*(T c, Point<T> a) { return {c * a.x, c * a.y}; }
template <typename T> inline Point<T> operator-(Point<T> a) { return -1 * a; }

template <typename IIt, typename OIt>
int convex_hull(IIt p0, IIt p1, OIt q0) {
	auto base = *min_element(p0, p1);
	using P = decltype(base);
	sort(p0, p1, [base](const P & p_, const P & q_) {
		P p = p_ - base, q = q_ - base;
		auto c = p % q;
		return c ? c > 0 : p * p < q * q;
	});
	OIt q1 = q0;
	while (p0 != p1) {
		while (q1 - q0 > 1 && (*(q1 - 1) - *(q1 - 2)) % (*p0 - *(q1 - 2)) <= 0)
			q1--;
		*(q1++) = *(p0++);
	}
	if (q1 - q0 == 2 && q0[0] == q0[1]) q1--;
	return q1 - q0;
}

constexpr int N = 100005;
Point<int> pts[N], hull[N];

void work() {
	int n, m = 0;
	scanf("%d", &n);
	Point<int> pt;
	map<Point<int>, int> id;
	rep (i, n) {
		scanf("%d%d", &pt.x, &pt.y);
		if (id.count(pt)) continue;
		pts[m++] = pt;
		id[pt] = i + 1;
	}
	int k = convex_hull(pts, pts + m, hull);
	double len = 0;
	rep (i, k) len += (hull[(i + 1) % k] - hull[i]).r();
	printf("%.2f\n", len);
	printf("%d", id[hull[0]]);
	range (i, 1, k) printf(" %d", id[hull[i]]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		work();
		if (t) printf("\n");
	}
	return 0;
}
