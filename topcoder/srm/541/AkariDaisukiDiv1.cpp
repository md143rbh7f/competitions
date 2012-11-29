#include <string>

using namespace std;

#define MOD 1000000007

int n;
string f;

int count( string s )
{
	int ans = 0;
	for( int i = 0; i + n <= s.size(); i++ ) ans += s.substr( i, n ) == f;
	return ans;
}

struct AkariDaisukiDiv1
{
	int countF( string a, string b, string c, string s, string _f, int k )
	{
		f = _f, n = f.size();

		string x = s;
		while( k && x.size() < n ) x = a + x + b + x + c, k--;
		long long ans = count( x );
		if( !k ) return ans;

		bool fixed = false;
		int plus;
		string l = x, m, r = x;
		while( k && !fixed )
		{
			string pre = l.substr( 0, n - 1 );
			string suf = r.substr( r.size() - n + 1, n - 1 );
			string _l = a + pre, _m = suf + b + pre, _r = suf + c;
			if( l == _l && m == _m && r == _r ) fixed = true;
			l = _l, m = _m, r = _r;
			plus = count( l ) + count( m ) + count( r );
			ans = ( 2 * ans + plus ) % MOD;
			k--;
		}
		if( !k ) return ans;

		while( k ) ans = ( plus + 2 * ans ) % MOD, k--;
		return ans;
	}
};
