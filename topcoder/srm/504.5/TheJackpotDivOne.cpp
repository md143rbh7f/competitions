#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct TheJackpotDivOne
{
	vector<ll> find( vector<ll> a, ll x )
	{
		int n = a.size();
		if( n == 1 )
		{
			a[0] += x;
			return a;
		}
		while(1)
		{
			int j = 0, k = 0;
			ll d = 0, r = 0;
			for( int i = 0; i < n; i++ )
			{
				if( a[i] < a[j] ) j = i;
				if( a[i] > a[k] ) k = i;
				d += a[i] / n;
				r += a[i] % n;
				if( r >= n )
				{
					d++;
					r %= n;
				}
			}
			if( a[j] == a[k] ) break;
			ll y = d + 1 - a[j];
			if( x <= y )
			{
				a[j] += x;
				x = 0;
				break;
			}
			else
			{
				a[j] += y;
				x -= y;
			}
		}
		if(x)
		{
			int m = x%n;
			for( int i = 0; i < n; i++ ) a[i] += x/n;
			for( int i = 0; i < m; i++ ) a[i]++;
		}
		sort(a.begin(),a.end());
		return a;
	}
};
