#include <iostream>

typedef long long ll;

using namespace std;

ll n, m, x, y, g, x1, y1, x2, y2, a1, a2;

int gcd( int a, int b )
{
	while( b != 0 )
	{
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	cin >> n >> m >> x >> y;
	g = gcd(x,y), x /= g, y /= g;
	x1 = (n/x)*x, y1 = x1/x*y; if( y1 <= m ) a1 = (ll)x1*y1;
	y2 = (m/y)*y, x2 = y2/y*x; if( x2 <= n ) a2 = (ll)x2*y2;
	if( a1 > a2 ) cout << x1 << " " << y1 << endl;
	else cout << x2 << " " << y2 << endl;
	return 0;
}
