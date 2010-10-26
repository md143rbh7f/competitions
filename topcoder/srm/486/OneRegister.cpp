#include <string>
#include <map>
#include <list>
#include <utility>

using namespace std;

typedef long long ll;
#define mp(a,b) make_pair((a),(b))

ll MAX=1<<30;
map<ll,string> b;
list< pair<ll,string> > q;

bool compare(string a,string b)
{
	if(a.size()<b.size()) return true;
	if(a.size()>b.size()) return false;
	return a<=b;
}

struct OneRegister
{
	string getProgram(int s,int t)
	{
		q.push_back(mp((ll)s,"")), q.push_back(mp((ll)1,"/"));
		while(!q.empty())
		{
			ll a=q.front().first;
			string p=q.front().second;
			q.pop_front();
			if(a>=MAX||(b.count(a)&&compare(b[a],p))) continue;
			b[a]=p;
			ll c1=a*a, c2=a<<1;
			q.push_back(mp(c1,p+"*")), q.push_back(mp(c2,p+"+"));
		}
		if(b.count(t)) return b[t];
		return ":-(";
	}
};
