#include <string>

using namespace std;

#define N 1<<20

int mem[N], n;

int rec( int mask )
{
	if( mem[mask] != -1 ) return mem[mask];
	for( int i = 0; i + 1 < n; i++ ) if( mask & ( 1 << i ) )
	{
		if( !( mask & ( 1 << ( i + 1 ) ) ) )
		{
			int next = mask - ( 1 << i );
			if( i + 1 < n - 1 ) next |= 1 << ( i + 1 );
			if( !rec( next ) ) return mem[mask] = 1;
		}
		else if( i + 3 < n && ( mask & ( 1 << ( i + 2 ) ) ) && !( mask & ( 1 << ( i + 3 ) ) ) )
		{
			int next = mask - ( 1 << i );
			if( i + 3 < n - 1 ) next |= 1 << ( i + 3 );
			if( !rec( next ) ) return mem[mask] = 1;
		}
	}
	return mem[mask] = 0;
}

struct EllysCheckers
{
	string getWinner( string board )
	{
		n = board.size();
		int mask = 0;
		for( int i = 0; i < n-1; i++ ) if( board[i] == 'o' ) mask |= 1<<i;
		for( int i = 0; i < 1<<n; i++ ) mem[i] = -1;
		return rec( mask ) ? "YES" : "NO";
	}
};
