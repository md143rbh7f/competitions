#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

#define SZ 100005
#define N 105
#define K 30

ll dp[N], overlap[2];
string s, f[K];
int m, kmp[SZ];

void build_kmp()
{
	for( int i = 1; i < m; i++ )
	{
		int & j = kmp[i];
		for( j = kmp[i-1]; j && s[j] != s[i]; j = kmp[j-1] );
		if( s[j] == s[i] ) j++;
	}
}

int match( int n )
{
	if( f[n].size() < m ) return 0;
	int ans = 0, j = 0;
	for( int i = 0; i < f[n].size(); i++ )
	{
		while( j && f[n][i] != s[j] ) j = kmp[j-1];
		if( f[n][i] == s[j] ) j++;
		if( j == m ) ans++, j = kmp[j-1];
	}
	return ans;
}

bool run( int T )
{
	int n;
	cin >> n >> s;
	if( cin.fail() ) return false;
	m = s.size(), build_kmp();
	int i = 0;
	for( ; i <= n && i < K; i++ ) dp[i] = match( i );
	for( int i = 1; i <= 2; i++ ) overlap[i%2] = dp[K-i] - dp[K-i-1] - dp[K-i-2];
	for( ; i <= n; i++ ) dp[i] = dp[i-1] + dp[i-2] + overlap[i%2];
	cout << "Case " << T << ": " << dp[n] << endl;
	return true;
}

int main()
{
	f[0] = "0", f[1] = "1";
	for( int i = 2; i < K; i++ ) f[i] = f[i-1] + f[i-2];
	for( int T = 1; run(T); T++ );
	return 0;
}
