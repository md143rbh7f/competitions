#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

bool t[44777778];

struct TheCoffeeTimeDivOne
{
	ll find( int n, vi tea )
	{
		ll ct = 0;
		rep(i,tea.size()) t[tea[i]] = true;
		rep(x,2)
		{
			int inc = 0, last = 0;
			for( int i = n; i; i-- ) if(x==t[i])
			{
				if(inc==0) ct += last+51+i;
				else ct += last-i+4;
				last = i;
				inc = (inc+1)%7;
			}
			ct += last;
		}
		return ct;
	}
};
