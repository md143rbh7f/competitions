#include <map>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

map<string,double> utot;

struct BatchSystemRoulette
{
	vector<double> expectedFinishTimes( vi t, vs usr )
	{
		int n = t.size();
		vector<double> ans(t.begin(),t.end());
		rep(i,n) utot[usr[i]] += t[i];
		rep(i,n) rep(j,n) if(utot[usr[i]]>utot[usr[j]]) ans[i] += t[j];
		rep(i,n) rep(j,n) if(i!=j&&utot[usr[i]]==utot[usr[j]]) ans[i] += 0.5*t[j];
		return ans;
	}
};
