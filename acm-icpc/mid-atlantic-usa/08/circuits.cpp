#include <cstdio>
#include <list>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define N 26
#define NN N*N

list<double> e[NN];
char a[2], b[2], & x = a[0], & y = b[0];
int T;

bool out( double d )
{
	printf( "Circuit %d: %.3lf\n", T, d );
	return true;
}

inline int id( int i, int j )
{ return i < j ? i * N + j : i + j * N; }

bool run()
{
	int n;
	scanf( "%d", &n );
	if( !n ) return false;

	for( int i = 0; i < NN; i++ ) e[i].clear();

	for( int i = 0; i < n; i++ )
	{
		int r;
		scanf( "%s%s%d", a, b, &r );
		if( x == y ) return out( -1 );
		e[id(x-'A',y-'A')].push_back(r);
	}

	for(;;)
	{
		bool update = false;

		for( int i = 0; i < N; i++ ) for( int j = 0; j < N; j++ )
		{
			list<double> & l = e[id(i,j)];
			if( l.size() <= 1 ) continue;
			double x = 0;
			foreach( it, l ) x += 1 / *it;
			l.clear();
			l.push_back( 1 / x );
			update = true;
		}

		for( int i = 1; i < N - 1; i++ )
		{
			list<int> v;
			for( int j = 0; j < N; j++ ) if( e[id(i,j)].size() ) v.push_back(j);
			if( v.size() != 2 ) continue;
			int j = v.front(), k = v.back();
			list<double> & rj = e[id(i,j)], & rk = e[id(i,k)];
			if( rj.size() > 1 || rk.size() > 1 ) continue;
			e[id(j,k)].push_back( rj.front() + rk.front() );
			rj.clear(), rk.clear();
			update = true;
		}

		if( !update ) break;
	}

	if( e[N-1].empty() ) return out( -1 );
	for( int i = 0; i < NN; i++ ) if( e[i].size() && i != N-1 )
		return out( -1 );

	return out( e[N-1].front() );
}

int main()
{
	for( T = 1; run(); T++ );
	return 0;
}
