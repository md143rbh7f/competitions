#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

template <typename T>
struct point
{
T x, y;
double p;
inline point<T> & operator-=(const point<T> & o) { x -= o.x, y -= o.y; return *this; }
inline point<T> operator-(const point<T> & o) const { auto p = *this; return p -= o; }
inline T operator*(const point<T> & o) { return x * o.x + y * o.y; }
inline T operator%(const point<T> & o) const { return x * o.y - y * o.x; }
inline bool operator==(const point<T> & o) const { return x == o.x && y == o.y; }
inline bool operator!=(const point<T> & o) const { return !(*this == o); }
};

struct Constellation
{
	double expectation(vi x, vi y, vi p)
	{
		int n = x.size();
		vector<point<int>> pt(n);
		rep(i,n) pt[i] = {x[i], y[i], 0.001 * p[i]};
		double ans = 0;
		for(auto & i : pt) for(auto & j : pt) if(i != j)
		{
			double e = i.p * j.p, pos = 1, neg = 1;
			point<int> ij = j - i;
			int r = ij * ij;
			for(auto & k : pt) if(k != i && k != j)
			{
				point<int> ik = k - i;
				int c = ij % ik, d = ij * ik;
				if(c > 0) pos *= 1 - k.p;
				else if(c < 0 || d < 0 || d > r) neg *= 1 - k.p;
			}
			ans += e * (1 - pos) * neg * (i % j) / 2;
		}
		return ans;
	}
};
