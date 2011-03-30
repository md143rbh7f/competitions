#include <map>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 41
#define MAXS 1601
#define MOD 1000000007

// index%2, inc/dec, s[index], sum
int n, ans, I, dp[2][2][MAX][MAXS];

inline void add( int & a, int & b ) { a = ( a + b ) % MOD; }

struct FoxAverageSequence
{
	int theCount( vector<int> s )
	{
		n = s.size();
		if(s[0]>-1) dp[0][1][s[0]][s[0]] = 1;
		else rep(k,MAX) dp[0][1][k][k] = 1;
		rep(i,n-1)
		{
			I = i%2;
			rep(j,2) rep(k,MAX) rep(l,MAXS) if(dp[I][j][k][l])
			{
				if(s[i+1]>-1)
				{
					if( s[i+1]<=l/(i+1) && ( j || s[i+1]>=k ) ) add( dp[1-I][s[i+1]>=k][s[i+1]][l+s[i+1]], dp[I][j][k][l] );
				}
				else
				{
					if(j) rep(x,min(k,1+l/(i+1))) add( dp[1-I][0][x][x+l], dp[I][j][k][l] );
					REP(x,k,1+l/(i+1)) add( dp[1-I][1][x][x+l], dp[I][j][k][l] );
				}
				dp[I][j][k][l] = 0;
			}
		}
		rep(j,2) rep(k,MAX) rep(l,MAXS) add( ans, dp[(n-1)%2][j][k][l] );
		return ans;
	}
};
