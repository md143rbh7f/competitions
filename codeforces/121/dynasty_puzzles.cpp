#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int best[26][26];
char buf[15];

int main()
{
	int n;
	scanf( "%d", &n );

	for( int i = 0; i < n; i++ )
	{
		scanf( "%s", buf );
		int len = strlen( buf ), a = buf[0] - 'a', b = buf[len-1] - 'a';
		for( int c = 0; c < 26; c++ ) if( best[c][a] ) best[c][b] = max( best[c][b], best[c][a] + len );
		best[a][b] = max( best[a][b], len );
	}

	int ans = 0;
	for( int c = 0; c < 26; c++ ) ans = max( ans, best[c][c] );
	printf( "%d\n", ans );

	return 0;
}
