#include <map>
#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define mod_add(a,b) a = ( a + b ) % MOD

#define MAXN 6
#define MAXL 51
#define MAXS MAXN*MAXL
#define C 26

int accepted[MAXS], g[MAXS][C], dp[2][MAXS][1<<MAXN], MOD = 1000000009;
map<string,int> id;

struct RequiredSubstrings
{
	int solve( vector<string> w, int cnt, int L )
	{
		int N = w.size(), S = 0;
		rep(i,N) rep(j,w[i].size()+1)
		{
			string state = w[i].substr(0,j);
			if(!id.count(state)) id[state] = S++;
		}
		foreach(iter,id)
		{
			string s = iter->first;
			rep(c,C)
			{
				string t = s + (char)('a'+c);
				while(!id.count(t)) t = t.substr(1);
				g[id[s]][c] = id[t];
			}
			rep(i,N) if( s.find(w[i]) != string::npos ) accepted[id[s]] |= 1<<i;
		}
		dp[0][0][0] = 1;
		rep(len,L)
		{
			int l = len%2;
			rep(s,S) rep(m,1<<N) dp[1-l][s][m] = 0;
			rep(s,S) rep(m,1<<N) rep(c,C) mod_add( dp[1-l][g[s][c]][m|accepted[g[s][c]]], dp[l][s][m] );
		}
		int ans = 0;
		rep(s,S) rep(m,1<<N) if( __builtin_popcount(m) == cnt ) mod_add( ans, dp[L%2][s][m] );
		return ans;
	}
};
