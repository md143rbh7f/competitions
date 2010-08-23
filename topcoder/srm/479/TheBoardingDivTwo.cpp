#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int perm[8], s[16], wait[8];
bool fix[8];

struct TheBoardingDivTwo
{
	int find( vi p, int bt )
	{
		int n = p.size(), m = 0, ans = 0;
		rep(i,n) --p[i], fix[p[i]] = p[i]>=0;
		rep(i,n) if(!fix[i]) perm[m++] = i;
		do
		{
			int q = 0;
			rep(i,n) s[i] = p[i]>=0 ? p[i] : perm[q++], s[i+n] = -1, wait[i] = 0;
			bool works = false;
			rep(t,bt)
			{
				for( int i=2*n-1; i>=0; i-- ) if(s[i]>=0)
				{
					int x = s[i];
					if(i==x+n)
					{
						if(wait[x]==74) s[i] = -1;
						else wait[x]++;
					}
					else if( i<x+n && s[i+1]==-1 ) s[i+1] = x, s[i] = -1;
				}
				works = true;
				rep(i,n) if(wait[i]<74) works = false;
				if(works) break;
			}
			if(works) ans++;
		}
		while(next_permutation(perm,perm+m));
		return ans;
	}
};
