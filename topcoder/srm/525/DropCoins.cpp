#include <string>
#include <vector>

using namespace std;

#define MAX 911
#define N 34

int cnt[N][N];

struct DropCoins
{
	int getMinimum( vector<string> board, int K )
	{
		int best = MAX, n = board.size(), m = board[0].size();
		for( int i = 1; i <= n; i++ ) for( int j = 1; j <= m; j++ )
			cnt[i][j] = ( board[i-1][j-1] == 'o' ) + cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		for( int k = i; k < n; k++ ) for( int l = j; l < m; l++ )
		if( cnt[k+1][l+1] - cnt[k+1][j] - cnt[i][l+1] + cnt[i][j] == K )
			best = min( best, i + j + ( n - 1 - k ) + ( m - 1 - l ) + min( i, n - 1 - k ) + min( j, m - 1 - l ) );
		return best == MAX ? -1 : best;
	}
};
