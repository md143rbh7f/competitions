#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 50
#define P 11
#define L (1<<P)
#define M (N*L)

int n, ns, q, p, t, suf[M], ord[P+1][M], cnt[M];
string str[N];

int len( int a ) { return str[a/L].size() - (a%L); }

bool lthan( int a, int b )
{
	if( ord[p][a] != ord[p][b] ) return ord[p][a] < ord[p][b];
	int la = len(a), lb = len(b);
	if( la > t && lb > t ) return ord[p][a+t] < ord[p][b+t];
	if( lb > t ) return true;
	return false;
}

int lcp( int a, int b, int lvl = P )
{
	if( lvl == -1 ) return 0;
	if( ord[lvl][a] != ord[lvl][b] ) return lcp( a, b, lvl-1 );
	int la = len(a), lb = len(b), sz = 1<<lvl;
	if( la > sz && lb > sz ) return sz + lcp( a + sz, b + sz, lvl-1 );
	return min( sz, min( len(a), len(b) ) );
}

void query( int k )
{
	if( k > cnt[ns-1] )
	{
		cout << "INVALID" << endl;
		return;
	}

	int l = 0, r = ns-1;
	while( l < r )
	{
		int m = (l+r)/2;
		if( k <= cnt[m] ) r = m;
		else l = m + 1;
	}

	string & ans = str[suf[l]/L];
	int a = suf[l]%L, b = ans.size() - cnt[l] + k;
	REP(j,a,b) cout << ans[j];
	cout << endl;
}

int main()
{
	cin >> n;
	rep(i,n) cin >> str[i];

	rep(i,n) rep(j,str[i].size())
	{
		int id = i * L + j;
		ord[0][id] = str[i][j] - 'a';
		suf[ns++] = id;
	}

	for( ; p < P; p++ )
	{
		t = 1<<p;
		sort( suf, suf+ns, lthan );
		REP(i,1,ns) ord[p+1][suf[i]] = ord[p+1][suf[i-1]] + lthan( suf[i-1], suf[i] );
	}

	cnt[0] = len( suf[0] );
	REP(i,1,ns) cnt[i] = cnt[i-1] + len( suf[i] ) - lcp( suf[i-1], suf[i] );

	cin >> q;
	rep(i,q)
	{
		int k;
		cin >> k;
		query(k);
	}

	return 0;
}
