#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

struct ShoutterDiv2
{
	int count( vi s, vi t )
	{
		int n = s.size(), ans = 0;
		rep(i,n) REP(j,i+1,n) if( s[i] <= t[j] && s[j] <= t[i] ) ans++;
		return ans;
	}
};
