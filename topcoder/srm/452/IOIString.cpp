#include <vector>
#include <string>

using namespace std;

typedef long long ll;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int mod = 1000000007;
ll ans = 1, nans;
string s;

struct IOIString
{
	int countIOIs( vector<string> mask )
	{
		rep(i,mask.size()) s += mask[i];
		int n = s.size(), ni = 0, nq = 0;
		if( n<3 ) return 0;
		rep(i,n) if(s[i]=='I') ni++;
		rep(i,n) if(s[i]=='?') nq++;
		if( ni==0 ) nans++;
		rep(i,n) if( s[i]!='O' )
		{
			if( (s[i]=='I')==ni ) nans++;
			for( int d = 1; i+d < n; d += 2 )
			{
				int cnt = s[i]=='I';
				for( int j = i+d; j < n; j += d )
				{
					if( s[j]=='I' ) cnt++;
					if( s[j]=='O' ) break;
					if( cnt == ni ) nans++;
				}
			}
		}
		if( !nq ) return nans==0;
		while( nq-- ) ans = (ans*2)%mod;
		return (ans+mod-nans)%mod;
	}
};
