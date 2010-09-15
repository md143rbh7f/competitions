#include <map>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

map<string,ll> utot;
map<string,int> early;
vs usr;

bool comp( int i, int j )
{
	if(utot[usr[i]]<utot[usr[j]]) return true;
	if(utot[usr[i]]>utot[usr[j]]) return false;
	if(usr[i]==usr[j]) return i<j;
	return early[usr[i]]<early[usr[j]];
}

struct BatchSystem
{
	vi schedule( vi t, vs user )
	{
		int n = t.size();
		usr = user;
		rep(i,n) early[usr[i]] = 50;
		rep(i,n) utot[usr[i]] += t[i], early[usr[i]] = min(early[usr[i]],i);
		vi ans;
		rep(i,n) ans.push_back(i);
		sort(ans.begin(),ans.end(),comp);
		return ans;
	}
};
