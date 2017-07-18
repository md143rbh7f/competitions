#include <vector>
#include <iostream>
#include <set>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 10000

int n,l,p,d,ans;
vi loans[MAX+1];
multiset<int> q;

int main()
{
	while(1)
	{
		cin >> n >> l;
		if(cin.fail()) break;
		while(n--)
		{
			cin >> p >> d;
			loans[d].push_back(p);
		}
		for(int t=MAX;t>=0;t--)
		{
			rep(i,loans[t].size()) q.insert(loans[t][i]);
			rep(i,l)
			{
				if(q.empty()) break;
				ans+=*q.rbegin();
				q.erase(q.find(*q.rbegin()));
			}
		}
		cout << ans << endl;

		rep(i,MAX+1) loans[i].clear();
		q.clear();
		ans=0;
	}
	return 0;
}
