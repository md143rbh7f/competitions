#include <algorithm>
#include <cstdio>

using namespace std;

int x[50], K, N, gap;

int main()
{
	scanf( "%d", &K );
	for( int k = 1; k <= K; k++ )
	{
		scanf( "%d", &N );
		for( int i = 0; i < N; i++ ) scanf( "%d", &x[i] );
		sort(x,x+N);
		gap = 0;
		for( int i = 1; i < N; i++ ) if( x[i] - x[i-1] > gap ) gap = x[i] - x[i-1];
		printf( "Class %d\nMax %d, Min %d, Largest gap %d\n", k, x[N-1], x[0], gap );
	}
	return 0;
}
