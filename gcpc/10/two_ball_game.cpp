#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
template <typename T> T read_next(istream & is = cin) { T x; is >> x; return x; }

template <typename T>
struct point
{
T x, y;
inline point<T> & operator+=(const point<T> & o) { x += o.x, y += o.y; return *this; }
inline point<T> operator+(const point<T> & o) const { auto p = *this; return p += o; }
inline point<T> & operator-=(const point<T> & o) { x -= o.x, y -= o.y; return *this; }
inline point<T> operator-(const point<T> & o) const { auto p = *this; return p -= o; }
inline T operator*(const point<T> & o) { return x * o.x + y * o.y; }
inline T operator%(const point<T> & o) const { return x * o.y - y * o.x; }
inline bool operator==(const point<T> & o) const { return x == o.x && y == o.y; }
inline bool operator<(const point<T> & o) const { return x < o.x || (x == o.x && y < o.y); }
inline bool operator()(const point & p, const point & q) const
{
	auto ap = p - *this, aq = q - *this;
	T c = ap % aq;
	return c ? c > 0 : ap * ap < aq * aq;
}
inline T r() const { return hypot(x, y); }
inline T q() const { return atan2(y, x); }
};
template <typename T> inline point<T> operator*(T c, point<T> a) { return {c * a.x, c * a.y}; }
template <typename T> inline point<T> operator-(point<T> a) { return -1 * a; }

template <typename T>
vector<point<T>> convex_hull(vector<point<T>> & pt)
{
	auto p0 = *min_element(all(pt));
	sort(all(pt), p0);
	int n = pt.size();
	vector<point<T>> ans;
	rep(i,n + 1)
	{
		auto & p = pt[i%n];
		while(ans.size() >= 2
		&& (ans.back() - ans[ans.size()-2]) % (p - ans.back()) <= 0)
			ans.pop_back();
		if(i < n) ans.push_back(p);
	}
	return ans;
}

void run()
{
	int n = read_next<int>();
	vector<point<double>> pt;
	rep(i,n) pt.push_back({read_next<double>(), read_next<double>()});
	auto hull = convex_hull(pt);
	vector<set<point<double>>> st{{pt[0], pt[1]}, {pt[2], pt[3]}};
	vector<int> qt;
	for(auto & p : hull) rep(i,2) if(st[i].count(p)) qt.push_back(i);
	cout << (qt.size() == 4 && qt[0] == qt[2] ? "IM" : "") << "POSSIBLE" << endl;
}

int main()
{
	for(int x = read_next<int>(); x; x--) run();
	return 0;
}
