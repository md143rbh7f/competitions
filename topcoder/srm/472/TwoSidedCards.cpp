#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define MAX 60

int mod = 1000000007;
ll g[50], c[MAX][MAX], f[MAX];

class TwoSidedCards
{
	public:
	int theCount( vi t, vi h )
	{
		c[0][0] = 1;
		REP(i,1,MAX)
		{
			c[i][0] = 1;
			REP(j,1,MAX) c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
		}
		
		REP(i,1,MAX) rep(j,i/2+1)
		{
			ll cur = (c[i][2*j]*(j?2:1))%mod;
			int a = i, b = j;
			while( a )
			{
				cur *= a--;
				while( b && cur%2==0 ) cur/=2, b--;
				cur %= mod;
			}
			f[i] = (f[i]+cur)%mod;
		}
		
		int n = t.size(), left = n;
		rep(i,n) g[t[i]-1] |= 1LL<<(h[i]-1), g[h[i]-1] |= 1LL<<(t[i]-1);
		rep(i,n) rep(j,n) if( g[i]&(1LL<<j) ) g[i] = g[j] = g[i]|g[j];

		ll ans = 1;
		rep(i,n)
		{
			ll tmp = g[i];
			int cnt = 0;
			while( tmp )
			{
				if( tmp&1 ) cnt++;
				tmp >>= 1;
			}
			if( !cnt ) continue;
			tmp = g[i];
			rep(j,n) if( tmp&(1LL<<j) ) g[j] = 0;
			ans = (((ans*c[left][cnt])%mod)*f[cnt])%mod;
			left -= cnt;
		}
		return (int)ans;
	}
};
