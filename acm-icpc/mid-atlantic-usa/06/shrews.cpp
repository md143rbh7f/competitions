#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define irep(i,n) REP(i,1,n+1)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

int n,m;
bool ok;
string d,cn,ct,buf;
vector<string> pn,g,pt;
set< pair<string,string> > p;

int main()
{
	cin>>d;
	n=d.size();
	rep(i,n) d[i]=d[i]=='D';
	while(1)
	{
		cin>>buf;
		if(buf[0]=='*') break;
		pn.push_back(buf);
		cin>>buf;
		g.push_back(buf);
		cin>>buf;
		rep(i,n) buf[i]-='0';
		pt.push_back(buf);
	}
	m=pn.size();
	while(1)
	{
		cin>>cn;
		if(cn[0]=='*') break;
		cin>>ct;
		rep(i,m) if(g[i][0]=='F') rep(j,m) if(g[j][0]=='M')
		{
			ok=true;
			rep(k,n) if(ct[k]-'0'!=((d[k]&&(pt[i][k]||pt[j][k]))||(pt[i][k]&&pt[j][k]))) ok=false;
			if(ok) p.insert(mp(pn[i],pn[j]));
		}
		cout<<cn<<" by ";
		foreach(i,p) cout<<(i==p.begin()?"":" or ")<<i->first<<"-"<<i->second;
		cout<<endl;
		p.clear();
	}
	return 0;
}
