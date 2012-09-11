#include <algorithm>
#include <vector>

using namespace std;

#define S 100000
#define M 4

int bad, k, mem[S], c[M], d[M], prod[M+1];
vector<int> x[M];
bool seen[S];

int rec( int m, int s )
{
	int & ans = mem[s];
	bool & done = seen[s];
	if( done ) return ans;
	done = true, ans = -1;
	if( m == bad ) return -1;
	for( int i = 0; i < M; i++ ) d[i] = ( s % prod[i+1] ) / prod[i];
	for( int i = 0; i < M; i++ ) if( d[i] > c[i] ) return -1;
	if( d[0] + d[1] + d[2] + d[3] == k )
	{
		ans = 0;
		for( int i = 0; i < M; i++ ) ans += x[i][d[i]];
	}
	else for( int i = 0; i < M; i++ ) ans = max( ans, rec( ( m + i ) % M, s + prod[i] ) );
	return ans;
}

struct SafeRemoval
{
	int removeThem( vector<int> seq, int _k )
	{
		int n = seq.size();
		k = _k;
		for( int i = 0; i < n; i++ ) x[ seq[i] % M ].push_back( seq[i] );
		prod[0] = 1;
		for( int i = 0; i < M; i++ )
		{
			c[i] = x[i].size();
			prod[i+1] = prod[i] * ( c[i] + 2 );
			bad = ( bad + i * c[i] ) % M;
			sort( x[i].begin(), x[i].end() );
			for( int j = c[i] - 1; j > 0; j-- ) x[i][j-1] += x[i][j];
			x[i].push_back( 0 );
		}
		return rec( 0, 0 );
	}
};
