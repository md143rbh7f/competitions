template <typename T>
struct Point
{
T x, y;
inline Point<T> & operator+=(const Point<T> & o) { x += o.x, y += o.y; return *this; }
inline Point<T> operator+(const Point<T> & o) const { auto p = *this; return p += o; }
inline Point<T> & operator-=(const Point<T> & o) { x -= o.x, y -= o.y; return *this; }
inline Point<T> operator-(const Point<T> & o) const { auto p = *this; return p -= o; }
inline T operator*(const Point<T> & o) { return x * o.x + y * o.y; }
inline T operator%(const Point<T> & o) const { return x * o.y - y * o.x; }
inline bool operator==(const Point<T> & o) const { return x == o.x && y == o.y; }
inline bool operator<(const Point<T> & o) const { return x < o.x || (x == o.x && y < o.y); }
inline bool operator()(const Point & p, const Point & q) const
{
	auto ap = p - *this, aq = q - *this;
	T c = ap % aq;
	return c ? c > 0 : ap * ap < aq * aq;
}
inline double r() const { return hypot(x, y); }
inline T q() const { return atan2(y, x); }
};
template <typename T> inline Point<T> operator*(T c, Point<T> a) { return {c * a.x, c * a.y}; }
template <typename T> inline Point<T> operator-(Point<T> a) { return -1 * a; }
template <typename T> ostream & operator<<(ostream & os, Point<T> p) { return os << "(" << p.x << ", " << p.y << ")"; }

template <typename T>
struct by_y
{
inline bool operator()(const Point<T> & p, const Point<T> & q) const
{ return p.y < q.y || (p.y == q.y && p.x < q.x); }
};

template <typename T>
vector<Point<T>> convex_hull(vector<Point<T>> & pt)
{
	auto p0 = *min_element(all(pt));
	sort(all(pt), p0);
	int n = pt.size();
	vector<Point<T>> ans;
	rep(i, n + 1)
	{
		auto & p = pt[i%n];
		while(ans.size() >= 2
		&& (ans.back() - ans[ans.size()-2]) % (p - ans.back()) <= 0)
			ans.pop_back();
		if(i < n) ans.push_back(p);
	}
	return ans;
}

template <typename T>
T polygon_area(vector<Point<T>> & pt)
{
	int n = pt.size();
	T ans = 0;
	rep(i,n) ans += pt[i] % pt[(i + 1)%n];
	return ans / 2;
}

template <typename T>
T closest(vector<Point<T>> & pt)
{
	if(pt.size() < 2) return 0;
	sort(all(pt));
	set<Point<T>, by_y<T>> u;
	T ans = INF;
	int lo = 0;
	for(auto & p : pt)
	{
		while(pt[lo].x < p.x - ans)
			u.erase(pt[lo++]);
		auto q = u.lower_bound({p.x - ans, p.y - ans});
		while(q != u.end() && q->y <= p.y + ans)
			ans = min(ans, (p - *(q++)).r());
		u.insert(p);
	}
	return ans;
}

template <typename T>
inline int sgn(T x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }

template <typename T>
struct Line
{
	Point<T> a, b;
	inline bool _intersects(const Line<T> & o) const { return sgn((o.a - a) % (b - a)) * sgn((o.b - a) % (b - a)) <= 0; }
	inline bool intersects(const Line<T> & o) const { return _intersects(o) && o._intersects(*this); }
};
