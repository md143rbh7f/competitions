#include <iostream>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 35

int n, u, r, a[N][N], b[N], k[N], p[N];

long long rec( int st, bool can )
{
	long long ans = -1e13;

	if( ( u - st ) % 2 == 0 )
	{
		ans = 0;
		rep(i,n) ans += a[st][i] * k[i];
	}

	if( st == u ) return ans;

	// permute
	rep(i,n) a[st+1][i] = a[st][p[i]] + r;
	ans = max( ans, rec( st + 1, true ) );

	// xor
	if( can )
	{
		rep(i,n) a[st+1][i] = a[st][i] ^ b[i];
		ans = max( ans, rec( st + 1, false ) );
	}

	return ans;
}

int main()
{
	cin >> n >> u >> r;
	rep(i,n) cin >> a[0][i];
	rep(i,n) cin >> b[i];
	rep(i,n) cin >> k[i];
	rep(i,n) cin >> p[i], p[i]--;
	cout << rec( 0, true ) << endl;
	return 0;
}
