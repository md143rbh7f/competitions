#include <string>
#include <vector>

using namespace std;

// 0 - didn't submit; 1 - challenged; 2 - failed systest; 3 - accept
#define get(mask,i) ( ( mask >> (2*i) ) & 3 )

long long dp[50][64];
int mod = 1000000007;

bool match( string s, int a )
{
	for( int i = 0; i < 3; i++ ) if( ( s[i] == 'N' && get(a,i) ) || ( s[i] == 'Y' && !get(a,i) ) ) return false;
	return true;
}

bool geq( int a, int b )
{
	int a_acc = 0, a_chal = 0, b_acc = 0, b_chal = 0;
	for( int i = 0; i < 3; i++ )
	{
		if( get( a, i ) == 3 ) a_acc++;
		if( get( b, i ) == 3 ) b_acc++;
		if( get( a, i ) == 1 ) a_chal++;
		if( get( b, i ) == 1 ) b_chal++;
	}
	return a_acc > b_acc || ( a_acc == b_acc && a_chal <= b_chal );
}

struct SRMSystemTestPhase
{
	int countWays( vector<string> desc )
	{
		int n = desc.size();
		for( int a = 0; a < 64; a++ ) if( match( desc[n-1], a ) ) dp[n-1][a] = 1;
		for( int i = n-1; i >= 0; i-- )
		for( int a = 0; a < 64; a++ ) if( match( desc[i], a ) )
		for( int b = 0; b < 64; b++ ) if( geq( a, b ) )
			dp[i][a] = ( dp[i][a] + dp[i+1][b] ) % mod;
		int ans = 0;
		for( int a = 0; a < 64; a++ ) ans = ( ans + dp[0][a] ) % mod;
		return ans;
	}
};
