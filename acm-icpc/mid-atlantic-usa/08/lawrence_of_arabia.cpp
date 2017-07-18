#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define N 1005
#define f(x) ( rec( x, k - 1 ) + w[x][n] )

int s[N], s2[N], w[N][N], mem[N][N];

int rec( int n, int k )
{
	int & ans = mem[n][k];
	if( ans != -1 ) return ans;
	if( n == 0 ) return ans = 0;
	if( k == 0 ) return ans = w[0][n];

	int l = 1, fl = f(l), r = n - 1, fr = f(r);
	while( r - l >= 3 )
	{
		int d = ( r - l ) / 3;
		int m1 = l + d, fm1 = f(m1), m2 = r - d, fm2 = f(m2);
		if( fm1 < fm2 ) r = m2, fr = fm2;
		else l = m1, fl = fm1;
	}
	for( int m = l; m <= r; m++ )
	{
		int fm = f(m);
		if( fm < fl ) l = m, fl = fm;
	}

	return ans = fl;
}

bool run()
{
	int n, k;
	cin >> n >> k;
	if( !n && !k ) return false;

	for( int i = 0; i < n; i++ )
	{
		int v;
		cin >> v;
		s[i+1] = s[i] + v;
		s2[i+1] = s2[i] + v * v;
	}
	for( int i = 0; i < n; i++ )
	for( int j = i + 2; j <= n; j++ )
		w[i][j] = ( ( s[j] - s[i] ) * ( s[j] - s[i] ) - ( s2[j] - s2[i] ) ) / 2;
	
	memset( mem, -1, sizeof(mem) );
	cout << rec( n, k ) << endl;
	return true;
}

int main()
{
	while( run() );
	return 0;
}
