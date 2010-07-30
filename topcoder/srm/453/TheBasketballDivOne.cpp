#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int s[5], a[20], b[20];

struct TheBasketballDivOne
{
	int find( int n, int m )
	{
		set<vi> ans;
		int N = n*(n-1), tmp = 0;
		rep(i,n) REP(j,i+1,n) rep(k,2)
		{
			a[tmp] = i;
			b[tmp] = j;
			tmp++;
		}
		rep(mask,1<<N)
		{
			rep(i,n) s[i] = 0;
			rep(i,N) if( mask&(1<<i) ) s[a[i]]++; else s[b[i]]++;
			vi seq(s,s+n);
			sort(seq.begin(),seq.end());
			if(seq[n-1]==m) ans.insert(seq);
		}
		return ans.size();
	}
};
