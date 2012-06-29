#include <cstdio>
#include <set>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

int n, k;
set<long long> nums;

int main()
{
	scanf( "%d%d", &n, &k );
	for( int i = 0; i < n; i++ )
	{
		int x;
		scanf( "%d", &x );
		nums.insert(x);
	}

	int cnt = 0;
	foreach( it, nums ) cnt += nums.count( *it + k );
	printf( "%d\n", cnt );

	return 0;
}
