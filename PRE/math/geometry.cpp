/*
 * The Point<T> and Line<T> classes (where T is the scalar type), along with
 * several 2D geometry algorithms.
 */

/*
 * Most of the arithmetic operations here use the usual notation; additionally,
 * (*) and (%) refer to the dot and cross product.
 */
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

/*
 * Calculates the area of a polygon using cross products. The polygon may be
 * convex or concave, but cannot intersect itself.
 */
template <typename It>
auto polygon_area(It p0, It p1) -> decltype(p0->x) {
	int n = p1 - p0;
	decltype(p0->x) ans = 0;
	rep (i, n) ans += p0[i] % p0[(i + 1) % n];
	return ans / 2;
}

/*
 * Computes the vertices of the convex hull of a set of points using Graham's
 * scan. By default, points are returned in counterclockwise order, starting
 * from the lowest leftmost point. Duplicated vertices or points lying on the
 * edge (but which are not vertices) are not included. Returns the number of
 * vertices found.
 */
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

/*
 * Finds the distance between the closest pair of points in a set of points.
 */
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
		// For integral scalars:
		// auto q = w.lower_bound(*p - P{ceil(ans), ceil(ans)});
		// For floating-point scalars:
		// auto q = w.lower_bound(*p - P{ans, ans});
		while (q != w.end() && q->x <= p->x + ans)
			ans = min(ans, (*p - *(q++)).r());
		w.insert(*p);
	}
	return ans;
}

/*
 * A simple line (segment) class that detects line intersections.
 */
template <typename T>
inline int sgn(T x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }

template <typename T>
struct Line {
	Point<T> a, b;
	inline bool intersects(const Line & o) const { return crosses(o) && o.crosses(*this); }

	private:
	inline bool crosses(const Line & o) const { return sgn((o.a - a) % (b - a)) * sgn((o.b - a) % (b - a)) <= 0; }
};
