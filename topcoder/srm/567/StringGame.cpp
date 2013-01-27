#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 55
#define C 26

int s[N][C], n, m;
bool used[C], dead[N];

bool good( int i )
{
	int left = n - 1;
	rep(j,n) dead[j] = false;
	rep(c,C) used[c] = false;
	while(1)
	{
		bool changed = false;
		rep(c,C) if( !used[c] )
		{
			bool geq = true;
			rep(j,n) if( !dead[j] && s[i][c] < s[j][c] ) geq = false;
			if( geq )
			{
				used[c] = true;
				rep(j,n) if( !dead[j] && s[i][c] > s[j][c] )
					dead[j] = true, left--;
				changed = true;
				break;
			}
		}
		if( !changed ) break;
	}
	return left == 0;
}

struct StringGame
{
	vector<int> getWinningStrings( vector<string> strs )
	{
		n = strs.size(), m = strs[0].size();
		rep(i,n) rep(j,m) s[i][strs[i][j]-'a']++;
		vector<int> ans;
		rep(i,n) if( good( i ) ) ans.push_back( i );
		return ans;
	}
};
