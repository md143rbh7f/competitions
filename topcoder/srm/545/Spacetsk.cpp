#include <algorithm>

using namespace std;

#define MAX 2012
#define MOD 1000000007

long long choose[MAX][MAX], pre[MAX];

struct Spacetsk
{
	int countsets( int L, int H, int K )
	{
		if( K == 1 ) return ( L + 1 ) * ( H + 1 );

		choose[0][0] = 1;
		for( int i = 1; i < MAX; i++ )
		{
			choose[i][0] = 1;
			for( int j = 1; j <= i; j++ ) choose[i][j] = ( choose[i-1][j] + choose[i-1][j-1] ) % MOD;
		}

		for( int i = 1; i <= L || i <= H; i++ ) pre[i] = ( pre[i-1] + choose[i][K] ) % MOD;

		long long ans = ( ( L + 1 ) * choose[H+1][K] ) % MOD;
		for( int x = 1; x <= L; x++ ) for( int y = 1; y <= H; y++ ) if( __gcd( x, y ) == 1 )
		{
			int cnt = min( L / x, H / y ), last_x = cnt * x;
			ans = ( ans + 2 * ( ( L - last_x + 1 ) * choose[cnt+1][K] + x * pre[cnt] ) ) % MOD;
		}
		return ans;
	}
};
