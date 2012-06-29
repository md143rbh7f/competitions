#include <cstdio>
#include <set>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

int n;
long long k;
set<long long> factors, bad_nums;

long long gcd( long long a, long long b )
{
	while( b )
	{
		long long t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	scanf( "%d%lld", &n, &k );

	for( long long i = 1; i * i <= k; i++ ) if( k % i == 0 )
	{
		factors.insert( i );
		factors.insert( k / i );
	}

	for( int i = 0; i < n; i++ )
	{
		long long bad;
		scanf( "%lld", &bad );
		bad_nums.insert( gcd( bad, k ) );
	}

	int ans = 0;
	foreach( factor, factors )
	{
		bool ok = true;
		foreach( bad, bad_nums ) if( (*bad) % (*factor) == 0 ) ok = false;
		ans += ok;
	}
	printf( "%d\n", ans );

	return 0;
}
