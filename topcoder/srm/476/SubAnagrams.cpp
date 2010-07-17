#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define MAX 501

int canon[MAX][MAX][26], dp[MAX][MAX];

struct SubAnagrams
{
	int maximumParts( vector<string> sw )
	{
		string s;
		rep(i,sw.size()) s += sw[i];
		int n = s.length(), best = 0;
		for( int i = n-1; i >= 0; i-- )
		{
			rep(k,26) canon[i][n][k] = canon[i+1][n][k];
			canon[i][n][s[i]-'A']++;
		}
		rep(i,n) REP(j,i+1,n+1) rep(k,26) canon[i][j][k] = canon[i][n][k]-canon[j][n][k];
		rep(i,n) dp[i][n] = 1;
		for( int j = n-1; j >= 0; j-- ) rep(i,j) REP(k,j+1,n+1)
		{
			bool works = true;
			rep(l,26) if( canon[i][j][l]>canon[j][k][l] ) works = false;
			if( works ) dp[i][j] = max( dp[i][j], dp[j][k]+1 );
		}
		rep(i,n+1) best = max( best, dp[0][i] );
		return best;
	}
};
