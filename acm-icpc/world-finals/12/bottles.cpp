#include <cstdio>
#include <iostream>

using namespace std;

#define PI 3.14159265358979323

int n, N, T;
double a[15], b[30], xl, xh, inc;

double vol( double x )
{
	double ans = 0;
	for( int p = N; p >= 0; p-- ) ans = x * ans + b[p];
	ans *= PI;
	return ans;
}

void run()
{
	N = 2 * n + 1;
	for( int p = 0; p <= N; p++ ) b[p] = 0;
	for( int i = 0; i <= n; i++ ) for( int j = 0; j <= n; j++ ) b[i+j+1] += ( a[i] * a[j] ) / ( i + j + 1 );

	double base = vol( xl ), tot = vol( xh ) - base;
	printf( "Case %d: %.2lf\n", T, tot );
	if( tot < inc )
	{
		printf( "insufficient volume\n" );
		return;
	}

	bool first = true;
	for( int i = 1; i <= 8 && i * inc < tot; i++ )
	{
		double dx = 0;
		for( double d = 128; d; d /= 2 ) if( xl + dx + d <= xh && vol( xl + dx + d ) - base <= i * inc ) dx += d;
		if( !first ) printf( " " );
		else first = false;
		printf( "%.2lf", dx );
	}
	printf( "\n" );
}

int main()
{
	for( T = 1; ; T++ )
	{
		cin >> n;
		if( cin.fail() ) break;
		for( int i = 0; i <= n; i++ ) cin >> a[i];
		cin >> xl >> xh >> inc;
		run();
	}
	return 0;
}
