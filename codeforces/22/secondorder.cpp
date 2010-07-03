#include <algorithm>
#include <cstdio>

using namespace std;

int nums[100], n;

int main()
{
	scanf( "%d", &n );
	for( int i = 0; i < n; i++ ) scanf( "%d", &nums[i] );
	sort( nums, nums+n );
	for( int i = 1; i < n; i++ )
	if( nums[i]>nums[0] )
	{
		printf( "%d", nums[i] );
		return 0;
	}
	printf( "NO" );
	return 0;
}
