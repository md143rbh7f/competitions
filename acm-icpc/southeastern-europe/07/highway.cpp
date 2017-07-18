#include <set>
#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

#define mp(a,b) make_pair((a),(b))
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

int l,d,n,ans;
double x,y,s;
multiset< pair<double,double> > q;

int main()
{
	while(1)
	{
		cin >> l >> d >> n;
		if(cin.fail()) break;
		while(n--)
		{
			cin >> x >> y;
			s = sqrt(1.0*d*d-y*y);
			q.insert(mp(x+s,x-s));
		}
		s=-1e13;
		foreach(i,q) if(i->second>s) s=i->first, ans++;
		cout << ans << endl;
		ans=0, q.clear();
	}
	return 0;
}
