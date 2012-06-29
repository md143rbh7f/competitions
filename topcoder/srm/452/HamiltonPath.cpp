#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

int n, x, y, mod = 1000000007;
ll ans = 1;
bool seen[50];
vi g[50];

int len( int i )
{
	seen[i] = true;
	foreach(j,g[i]) if( !seen[*j] ) return len(*j)+1;
	return 1;
}

struct HamiltonPath
{
	int countPaths( vector<string> roads )
	{
		n = roads.size();
		rep(i,n) rep(j,n) if( roads[i][j]=='Y' ) g[i].push_back(j);
		rep(i,n) if( g[i].size()>2 ) return 0;
		rep(i,n) if( g[i].size()<=1 && !seen[i] ) len(i)>1 ? x++ : y++;
		rep(i,n) if( !seen[i] ) return 0;
		rep(i,x+y) ans = (ans*(i+1))%mod;
		rep(i,x) ans = (ans*2)%mod;
		return ans;
	}
};
