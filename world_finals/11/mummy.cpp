#include <algorithm>
#include <iostream>

using namespace std;

#define iter(i,a,b) for(__typeof__(a) i=(a);i!=(b);i++)
#define rep(i,n) iter(i,0,n)

#define N 100005
#define INF 123456789
#define T (1<<20)

struct square
{
	int x, y, x0, x1, y0, y1;
};

inline bool by_x( const square & a, const square & b )
{
	return a.x < b.x;
}

inline bool by_y( square * a, square * b )
{
	return a->y < b->y;
}

int n, m, val[6*N], buf[6*N];
square s[N], * q[N], * zero;

int query( int x, int y, int v = 0, int i = 0, int a = 0, int b = m )
{
	if( y <= a || b <= x ) return v ? val[i] + buf[i] : INF;
	if( x <= a && b <= y ) return val[i] + ( buf[i] += v );
	int j = 2 * i + 1, k = 2 * i + 2;
	buf[j] += buf[i], buf[k] += buf[i], buf[i] = 0;
	int c = ( a + b ) / 2;
	return val[i] = min( query( x, y, v, j, a, c ), query( x, y, v, k, c, b ) );
}

bool possible( int t )
{
	iter(i,s+0,s+n)
	{
		i->y0 = i->y - t, i->y1 = i->y + t + 1;
		i->x0 = i->x - t, i->x1 = i->x + t + 1;
	}

	m = 0;
	for( square ** i = q, ** j = q; j != q + n; m++ )
	{
		int y = min( i != q + n ? (*i)->y0 : INF, (*j)->y1 );
		for( ; i != q + n && (*i)->y0 == y; i++ ) (*i)->y0 = m;
		for( ; j != q + n && (*j)->y1 == y; j++ ) (*j)->y1 = m;
	}

	rep(i,3*m) val[i] = buf[i] = 0;

	for( square * i = s, * j = s; j != s + n; )
	{
		int x = min( i != s + n ? i->x0 : INF, j->x1 );
		for( ; i != s + n && i->x0 == x; i++ ) query( i->y0, i->y1, 1 );
		for( ; j != s + n && j->x1 == x; j++ ) query( j->y0, j->y1, -1 );
		if( -t <= x && x <= t && query( zero->y0, zero->y1 ) == 1 ) return true;
	}
	return false;
}

bool run( int case_num )
{
	cin >> n;
	if( n == -1 ) return false;

	rep(i,n) cin >> s[i].x >> s[i].y;
	s[n].x = s[n].y = 0, n++;
	rep(i,n) q[i] = &s[i];
	sort( s, s + n, by_x ), sort( q, q + n, by_y );
	iter(i,s+0,s+n) if( !i->x && !i->y ) zero = i;

	int t = T;
	for( int d = T / 2; d; d /= 2 ) if( !possible( t - d ) ) t -= d;

	cout << "Case " << case_num << ": ";
	if( t == T ) cout << "never";
	else cout << t;
	cout << endl;

	return true;
}

int main()
{
	for( int t = 1; run(t); t++ );
	return 0;
}
