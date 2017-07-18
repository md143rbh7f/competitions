#include <cstring>
#include <iostream>
#include <set>
#include <string>

using namespace std;

#define L 101
#define M 600

bool g[M][M];
int n, l, m, dp[L][M], slen, ans;
string s[M];
set<string> unique;

int main()
{
	while(1)
	{
		cin >> n >> l >> m;
		if( !n && !l && !m ) break;
		unique.clear();
		for( int i = 0; i < m; i++ )
		{
			cin >> s[i];
			if(!unique.count(s[i])) unique.insert(s[i]);
			else i--, m--;
		}
		slen = s[0].size();
		for( int i = 0; i < m; i++ ) for( int j = 0; j < m; j++ )
		{
			g[i][j] = true;
			for( int k = 1; k < slen; k++ ) if( s[i][k] != s[j][k-1] ) g[i][j] = false;
		}
		memset(dp,0,sizeof(dp));
		for( int i = 0; i < m; i++ ) dp[slen][i] = 1;
		for( int k = slen; k < l; k++ ) 
		for( int i = 0; i < m; i++ ) for( int j = 0; j < m; j++ ) 
		if( g[i][j] )
			dp[k+1][j] += dp[k][i];
		ans = 0;
		for( int i = 0; i < m; i++ ) ans += dp[l][i];
		cout << ans << endl;
	}
}
