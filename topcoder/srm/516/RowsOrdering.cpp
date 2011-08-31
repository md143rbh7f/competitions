#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int MOD = 1000000007, n, m, best[50], cnt[50];

struct RowsOrdering
{
	int order( vector<string> rows )
	{
		n = rows.size(), m = rows[0].size();
		for( int j = 0; j < m; j++ )
		{
			for( int c = 0; c < 50; c++ ) cnt[c] = 0;
			for( int i = 0; i < n; i++ )
			{
				if( rows[i][j] >= 'a' && rows[i][j] <= 'z' ) cnt[rows[i][j]-'a']++;
				else cnt[rows[i][j]-'A'+26]++;
			}
			sort( cnt, cnt+50 );
			for( int c = 0; c < 50; c++ ) best[j] += cnt[49-c] * c;
		}
		sort( best, best+m );
		long long ans = 0;
		for( int j = 0; j < m; j++ ) ans = ( 50 * ans + best[j] ) % MOD;
		return ( ans + n ) % MOD;
	}
};
