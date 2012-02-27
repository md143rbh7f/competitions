#include <cstring>
#include <vector>

using namespace std;

#define MOD 1000000007
#define N 5
#define H 27
#define L 15

int x[N], l[N], mem[H*H*H*H*H], pow[N], magic[N][L];

inline int get_hash( int p )
{
	int hash = 0;
	for( int i = 0; i < N; i++ ) hash += pow[i] * ( magic[i][l[i]] + ( ( p >> i ) & 1 ) );
	return hash;
}

int rec( int p )
{
	int hash = get_hash(p), & ans = mem[hash];
	if( ans != -1 ) return ans;
	int state[N];
	for( int i = 0; i < N; i++ ) state[i] = ( x[i] >> l[i] ) - ( ( p >> i ) & 1 );
	bool zero = true;
	for( int i = 0; i < N; i++ ) if( state[i] ) zero = false;
	if( zero ) return ans = 1;
	ans = 0;
	for( int i = 0; i < N; i++ )
	{
		int j = ( i + 1 ) % N;
		if( !state[i] || !state[j] ) continue;
		if( 1 & state[i] & state[j] ) ans = ( ans + rec( p | ( 1 << i ) | ( 1 << j ) ) ) % MOD;
		l[i]++, l[j]++;
		ans = ( ans + rec( p & ( - 1 - ( 1 << i ) - ( 1 << j ) ) ) ) % MOD;
		l[i]--, l[j]--;
	}
	return ans;
}

struct EllysFiveFriends
{
	int getZero( vector<int> numbers )
	{
		pow[0] = 1;
		for( int i = 1; i < N; i++ ) pow[i] = pow[i-1] * H;
		for( int i = 0; i < N; i++ )
		{
			x[i] = numbers[i];
			int tmp = x[i];
			for( int j = 1; j < L; j++ )
			{
				magic[i][j] = magic[i][j-1] + ( tmp & 1 ) + 1;
				tmp >>= 1;
			}
		}
		memset( mem, -1, sizeof(mem) );
		return rec(0);
	}
};
