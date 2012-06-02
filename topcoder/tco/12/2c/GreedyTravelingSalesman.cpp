#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define N 35
#define MAX 9999
#define MIN 1

struct option
{
	int dist, next;
	option( int _dist, int _next ) : dist(_dist), next(_next) {}
	bool operator<( const option & o ) const
	{ return dist < o.dist || ( dist == o.dist && next < o.next ); }
};

int n, d[N][N];
bool seen[N];

int rec( int cur, bool used )
{
	seen[cur] = true;

	vector<option> o;
	for( int i = 0; i < n; i++ ) if( !seen[i] ) o.push_back( option( d[cur][i], i ) );
	sort( o.begin(), o.end() );

	if( o.size() == 1 )
	{
		seen[cur] = false;
		return used ? o[0].dist : MAX;
	}

	if( used )
	{
		int ans = o[0].dist + rec( o[0].next, true );
		seen[cur] = false;
		return ans;
	}

	// case 1: default
	int ans = o[0].dist + rec( o[0].next, false );

	// case 2: increase o[0].dist till it's barely below o[1].dist
	ans = max( ans, o[1].dist - ( o[1].next < o[0].next ) + rec( o[0].next, true ) );

	// case 3: increase o[0].dist until o[1] is optimal
	if( o[1] < option( MAX, o[0].next ) ) ans = max( ans, o[1].dist + rec( o[1].next, true ) );

	// case 4: decrease o[i].dist until o[i] is optimal
	for( int i = 1; i < o.size(); i++ ) if( o[0].dist > MIN || o[i].next < o[0].next )
		ans = max( ans, o[0].dist - ( o[0].next < o[i].next ) + rec( o[i].next, true ) );
	
	seen[cur] = false;
	return ans;
}

struct GreedyTravelingSalesman
{
	int worstDistance( vector<string> dig0, vector<string> dig1, vector<string> dig2, vector<string> dig3 )
	{
		vector<string> * dig[4] = { &dig0, &dig1, &dig2, &dig3 };
		n = dig0.size();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) for( int k = 0; k < 4; k++ )
			d[i][j] = 10 * d[i][j] + (*dig[k])[i][j] - '0';
		return rec( 0, false );
	}
};
