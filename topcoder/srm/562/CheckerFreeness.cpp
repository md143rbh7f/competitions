#include <algorithm>
#include <cmath>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct point
{
	double x, y;

	point( double _x, double _y ) : x( _x ), y( _y ) {}

	inline point operator-( const point & o ) const
	{ return point( x - o.x, y - o.y ); }

	inline double operator%( const point & o ) const
	{ return x * o.y - o.x * y; }

	inline double magnitude() const
	{ return hypot( x, y ); }

	inline double angle() const
	{ return atan2( y, x ); }

	inline bool operator()( const point & p, const point & q )
	{
		double ap = ( p - *this ).angle(), aq = ( q - *this ).angle();
		if( ap != aq ) return ap < aq;
		return ( p - *this ).magnitude() < ( q - *this ).magnitude();
	}
};

vector<point> convex_hull( vector<point> & pts )
{
	int n = pts.size();
	point start = pts[0];
	for( int i = 0; i < n; i++ )
	{
		point & p = pts[i];
		if( p.y < start.y || ( p.y == start.y && p.x < start.x ) )
			start = p;
	}
	sort( pts.begin(), pts.end(), start );

	vector<point> ans;
	for( int i = 0; i <= n; i++ )
	{
		point & p = pts[i%n];
		while( ans.size() >= 2
		&& ( ans.back() - ans[ans.size()-2] ) % ( p - ans.back() ) <= 0 )
			ans.pop_back();
		ans.push_back( p );
	}
	ans.pop_back();
	if( ans.size() == 1 ) ans.push_back( pts.back() );
	return ans;
}

inline bool opposite( double a, double b )
{ return a < 0 && b > 0 || a > 0 && b < 0; }

inline bool intersect( point & a, point & b, point & c, point & d )
{
	return opposite( ( c - a ) % ( b - a ), ( d - a ) % ( b - a ) )
		&& opposite( ( a - c ) % ( d - c ), ( b - c ) % ( d - c ) );
}

bool intersect( vector<point> & h, vector<point> & pts )
{
	int n = h.size(), m = pts.size();
	for( int i = 0; i < n; i++ )
	{
		point & a = h[i], & b = h[(i+1)%n];
		for( int j = 0; j < m; j++ ) for( int k = j + 1; k < m; k++ )
		if( intersect( a, b, pts[j], pts[k] ) )
			return true;
	}
	return false;
}

inline string concat( const vector<string> & strs )
{ return accumulate( strs.begin(), strs.end(), string() ); }

vector<point> parse( vector<string> & xstr, vector<string> & ystr )
{
	istringstream xs( concat( xstr ) ), ys( concat( ystr ) );
	int x, y;
	vector<point> ans;
	while( ( xs >> x ) && ( ys >> y ) ) ans.push_back( point( x, y ) );
	return ans;
}

struct CheckerFreeness
{
	string isFree( vector<string> wx, vector<string> wy, vector<string> bx, vector<string> by )
	{
		vector<point> w = parse( wx, wy ), wh = convex_hull( w );
		vector<point> b = parse( bx, by ), bh = convex_hull( b );
		return intersect( wh, b ) || intersect( bh, w ) ? "NO" : "YES";
	}
};
