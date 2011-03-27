#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>

using namespace std;

typedef pair<int,int> pii;
#define MAX 100001

int mx, my, w, x, y, tot, bestx = MAX, besty = MAX;
map<pii,int> xc, yc;
pii xfr[MAX], yfr[MAX];

int rev( int a )
{
	int b = 0;
	for( ; a; a /= 10 ) b = b*10 + a%10;
	return b;
}

pii frac( int a, int b )
{
	int g = __gcd(a,b);
	return make_pair( a/g, b/g );
}

int main()
{
	scanf( "%d%d%d", &mx, &my, &w );
	for( x = 1; x <= mx; x++ ) xfr[x] = frac(x,rev(x));
	for( y = 1; y <= my; y++ ) yfr[y] = frac(rev(y),y);
	for( x = 1; x <= mx; x++ ) xc[xfr[x]]++;
	for( x = mx, y = 1; x; x-- )
	{
		for( ; tot + xc[yfr[y]] < w && y <= my; y++ )
		{
			yc[yfr[y]]++;
			tot += xc[yfr[y]];
		}
		if( tot + xc[yfr[y]] >= w && (long long) x*y < (long long) bestx*besty ) bestx = x, besty = y;
		xc[xfr[x]]--;
		tot -= yc[xfr[x]];
	}
	if( bestx != MAX ) printf( "%d %d\n", bestx, besty );
	else printf( "-1\n" );
	return 0;
}
