#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

template <typename T>
struct Point {
T x, y;
inline Point & operator+=(const Point & o) { x += o.x, y += o.y; return *this; }
inline Point operator+(const Point & o) const { auto p = *this; return p += o; }
inline T operator%(const Point & o) const { return x * o.y - y * o.x; }
};
template <typename T> inline Point<T> operator*(T c, Point<T> a) { return {c * a.x, c * a.y}; }

using P = Point<double>;
struct Line { double x, y, c, q; };

inline bool by_q(Line &a, Line &b) { return a.q < b.q; }

inline P intersection(Line &a, Line &b) {
	return 1 / (a.x * b.y - b.x * a.y) * P{a.c * b.y - b.c * a.y , a.x * b.c - b.x * a.c};
}

constexpr int N = 3005;
constexpr double PI = atan2(0, -1);

Line ls[N];

int main() {
	int n, x, y, c;
	double q;
	scanf("%d", &n);
	rep (i, n) {
		scanf("%d%d%d", &x, &y, &c);
		q = atan2(y, x);
		if (q < 0) q += PI;
		ls[i] = {x, y, c, q};
	}
	sort(ls, ls + n, &by_q);

	double tot = 0;
	rep (i, n) {
		Line &l = ls[i];
		P sum {0, 0};
		range (j, 1, n) {
			P pt = intersection(l, ls[(i + j) % n]);
			tot += sum % pt;
			sum += pt;
		}
	}

	printf("%.7lf\n", 3 * tot / n / (n - 1) / (n - 2));
	return 0;
}
