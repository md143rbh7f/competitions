#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define MOD 1000000007

int n;
vi id;

vi operator*( vi a, vi b )
{
	vi ans(n);
	rep(i,n) if(a[i]) rep(j,n) if(b[j])
		ans[(i+j)%n] = ( ans[(i+j)%n] + ( (ll) a[i] * b[j] ) % MOD ) % MOD;
	return ans;
}

vi exp( vi e, ll p )
{
	if( !p ) return id;
	return ( p % 2 ? e : id ) * exp( e * e, p / 2 );
}

struct PenguinEmperor
{
	int countJourneys( int _n, ll t )
	{
		n = _n;

		id = vi(n);
		id[0] = 1;

		vi base[n];
		base[0] = id;
		REP(dt,1,n) 
		{
			vi del(n);
			del[dt] = del[n-dt] = 1;
			base[dt] = del * base[dt-1];
		}

		return ( base[t%n] * exp( base[n-1], t / n ) )[0];
	}
};
