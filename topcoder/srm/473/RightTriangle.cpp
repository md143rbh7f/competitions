typedef long long ll;
#define MAX 1000000
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int cnt[MAX];
bool r[MAX];

class RightTriangle
{
	public:
	ll triangleCount( int n, int m, int a, int b, int c )
	{
		if(n%2) return 0;
		ll ans = 0;
		int cur = 0;
		rep(i,m) cnt[((ll)a*i*i+(ll)b*i+(ll)c)%n]++;
		rep(i,2*n)
		{
			if( i<n ) cur += cnt[i];
			if( !r[i%n] && cur>0 )
			{
				cur--;
				r[i%n] = true;
			}
		}
		rep(i,n/2) if(r[i]&&r[i+n/2]) ans += m-2;
		return ans;
	}
};
