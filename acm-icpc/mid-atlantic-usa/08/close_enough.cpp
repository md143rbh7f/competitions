#include <iostream>

using namespace std;

inline double sub( int x ) { return x ? x - 0.5 : 0; }

int main()
{
	while(1)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if( !a && !b && !c && !d ) break;
		double lo = 9 * sub(b) + 4 * ( sub(c) + sub(d) );
		double hi = 9 * ( b + 0.5 ) + 4 * ( c + d + 1 );
		cout << ( lo <= a && a < hi ? "yes" : "no" ) << endl;
	}
	return 0;
}
