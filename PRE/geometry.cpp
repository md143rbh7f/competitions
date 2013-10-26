#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)
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
template <typename T> ostream & operator<<(ostream & os, point<T> p) { return os << "(" << p.x << ", " << p.y << ")"; }

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

template <typename T>
T polygon_area(vector<point<T>> && pt)
{
	int n = pt.size();
	T ans = 0;
	rep(i,n) ans += pt[i] % pt[(i + 1)%n];
	return ans / 2;
}
