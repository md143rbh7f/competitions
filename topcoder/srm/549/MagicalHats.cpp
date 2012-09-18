#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define N 13
#define S 1594323

vector<int> g;
int n, m, id[N][N], mem_ok[S], mem[S], pow[N];

// 0 = unknown, 1 = no coin, 2 = coin
inline int get( int s, int i ) { return ( s / pow[i] ) % 3; }

bool ok( int s )
{
	if( mem_ok[s] != -1 ) return mem_ok[s];

	mem_ok[s] = 0;
	bool base = true;
	for( int i = 0; i < n; i++ ) if( get( s, i ) == 0 )
	{
		base = false;
		bool ok0 = ok( s + pow[i] ), ok1 = ok( s + 2 * pow[i] );
		if( ok0 || ok1 ) mem_ok[s] = 1;
	}
	if( !base ) return mem_ok[s];

	int coins = 0;
	for( int i = 0; i < n; i++ ) if( get( s, i ) == 2 ) coins++;
	if( coins != m ) return false;

	for( int i = 0; i < g.size(); i++ )
	{
		int t = g[i], sum = 0;
		for( int j = 0; j < n; j++ ) if( ( t >> j ) & 1 ) sum += get( s, j );
		if( sum % 2 ) return false;
	}

	return mem_ok[s] = 1;
}

int rec( int s, int ng )
{
	int & ans = mem[s];
	if( ans != -1 ) return ans;
	if( !ng ) return ans = 0;

	for( int i = 0; i < n; i++ ) if( get( s, i ) == 0 )
	{
		int s0 = s + pow[i], s1 = s + 2 * pow[i];
		bool ok0 = ok( s0 ), ok1 = ok( s1 );
		int a0 = ok0 ? rec( s0, ng - 1 ) : -1;
		int a1 = ok1 ? 1 + rec( s1, ng - 1 ) : -1;
		if( ok0 && ok1 ) ans = max( ans, min( a0, a1 ) );
		else if( ok0 ) ans = max( ans, a0 );
		else if( ok1 ) ans = max( ans, a1 );
	}

	return ans;
}

struct MagicalHats
{
	int findMaximumReward( vector<string> board, vector<int> coins, int ng )
	{
		pow[0] = 1;
		for( int i = 1; i < N; i++ ) pow[i] = pow[i-1] * 3;

		m = coins.size();
		sort( coins.begin(), coins.end() );

		int x = board.size(), y = board[0].size();
		for( int i = 0; i < x; i++ ) for( int j = 0; j < y; j++ ) id[i][j] = board[i][j] == 'H' ? n++ : -1;
		set<int> e;
		for( int i = 0; i < x; i++ )
		{
			int s = 0;
			for( int j = 0; j < y; j++ ) if( id[i][j] != -1 ) s ^= 1 << id[i][j];
			if( s ) e.insert( s );
		}
		for( int j = 0; j < y; j++ )
		{
			int s = 0;
			for( int i = 0; i < x; i++ ) if( id[i][j] != -1 ) s ^= 1 << id[i][j];
			if( s ) e.insert( s );
		}
		for( set<int>::iterator it = e.begin(); it != e.end(); it++ ) g.push_back( *it );

		for( int s = 0; s < S; s++ ) mem_ok[s] = mem[s] = -1;
		if( !ok( 0 ) ) return -1;
		int num = rec( 0, ng ), ans = 0;
		for( int i = 0; i < num && i < m; i++ ) ans += coins[i];
		return ans;
	}
};
