#include <cstdio>
#include <vector>

using namespace std;

#define MAX 1005

vector<int> g[MAX];
bool seen[MAX];

bool dfs( int i )
{
	if( seen[i] ) return true;
	seen[i] = true;
	for( int j = 0; j < g[i].size(); j++ ) if( dfs( g[i][j] ) ) return true;
	return false;
}

void run( int C )
{
	int N;
	scanf( "%d", &N );
	for( int i = 0; i < N; i++ ) g[i].clear();
	for( int i = 0; i < N; i++ )
	{
		int m, parent;
		scanf( "%d", &m );
		for( int j = 0; j < m; j++ )
		{
			scanf( "%d", &parent );
			g[parent-1].push_back(i);
		}
	}

	bool diamond = false;
	for( int i = 0; i < N; i++ )
	{
		for( int j = 0; j < N; j++ ) seen[j] = false;
		if( dfs( i ) )
		{
			diamond = true;
			break;
		}
	}

	printf( "Case #%d: %s\n", C, diamond ? "Yes" : "No" );
}

int main()
{
	int T;
	scanf( "%d", &T );
	for( int i = 1; i <= T; i++ ) run( i );
}
