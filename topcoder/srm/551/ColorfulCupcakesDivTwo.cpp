#include <cstring>
#include <string>

using namespace std;

#define MOD 1000000007
#define M 3
#define N 55

int mem[M][M][N*N*N], id[4];

inline bool have( int s, int i ) { return ( s % id[i+1] ) / id[i] > 0; }

int ways( int first, int prev, int s )
{
	int & ans = mem[first][prev][s];
	if( ans != -1 ) return ans;
	if( !s ) return ans = first != prev;

	ans = 0;
	for( int i = 0; i < M; i++ ) if( prev != i && have( s, i ) ) ans = ( ans + ways( first, i, s - id[i] ) ) % MOD;
	return ans;
}

struct ColorfulCupcakesDivTwo
{
	int countArrangements( string cupcakes )
	{
		if( cupcakes.size() == 1 ) return 1;

		memset( mem, -1, sizeof(mem) );
		id[0] = 1;
		for( int i = 0; i < M; i++ ) id[i+1] = N * id[i];

		int s = 0, n = cupcakes.size(), ans = 0;
		for( int i = 0; i < n; i++ ) s += id[cupcakes[i]-'A'];
		for( int i = 0; i < M; i++ ) if( have( s, i ) ) ans = ( ans + ways( i, i, s - id[i] ) ) % MOD;
		return ans;
	}
};
