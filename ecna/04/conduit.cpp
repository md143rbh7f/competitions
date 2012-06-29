#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> segment;
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

// lines[ x, y, z ] is the line of points (x',y') such that that (x',y')*(-y,x) = z
// lines[ x, y, z ] has tangent vector (x,y) and normal vector (y,-x).
// a segment is represented a pair of longs (a,b), a<b, representing the dot product of each endpoint with the tangent vector (x,y)

// strategy: project every segment onto a line, then go through each line and count number of maximal non-overlapping segments

map< pair< pair< ll, ll >, ll >, vector<segment> > lines;

ll gcd( ll a, ll b )
{
	while(b)
	{
		ll t = a%b;
		a = b;
		b = t;
	}
	return a;
}

bool lthan( segment a, segment b )
{
	return a.first < b.first || ( a.first == b.first && a.second > b.second );
}

int main()
{
	while(1)
	{
		int n, cnt = 0;
		scanf( "%d", &n );
		if(!n) break;
		lines.clear();
		while(n--)
		{
			double X0, Y0, X1, Y1;
			scanf( "%lf%lf%lf%lf", &X0, &Y0, &X1, &Y1 );
			ll x0 = round(X0*100), y0 = round(Y0*100), x1 = round(X1*100), y1 = round(Y1*100);
			ll dx = x1 - x0, dy = y1 - y0;
			if( dx && dy )
			{
				if( dx < 0 ) dx = -dx, dy = -dy;
				ll g = gcd( dx, dy > 0 ? dy : -dy );
				dx /= g, dy /= g;
			}
			else if(dx) dx = 1;
			else if(dy) dy = 1;
			// ( dx, dy ) --- tangent vector
			// ( -dy, dx ) --- normal vector
			ll a = x0*dx + y0*dy, b = x1*dx + y1*dy;
			if( a > b ) swap(a,b);
			lines[ make_pair( make_pair( dx, dy ), -x0*dy + y0*dx ) ].push_back( make_pair( a, b ) );
		}
		foreach(line,lines)
		{
			sort( line->second.begin(), line->second.end(), lthan );
			ll last = -(1ll<<42);
			foreach(seg,line->second)
			{
				if( seg->first > last ) cnt++;
				if( seg->second > last ) last = seg->second;
			}
		}
		printf( "%d\n", cnt );
	}
}
