#include <algorithm>
#include <iostream>

using namespace std;

#define N 100005

int r[N], c[N], n;

int rec( int i )
{
	int & ans = c[i];
	if( ans ) return ans;
	int a = i && r[i] > r[i-1] ? rec( i - 1 ) : 0;
	int b = i < n - 1 && r[i] > r[i+1] ? rec( i + 1 ) : 0;
	return ans = max( a, b ) + 1;
}

int main()
{
	cin >> n;
	for( int i = 0; i < n; i++ ) cin >> r[i];
	long long ans = 0;
	for( int i = 0; i < n; i++ ) ans += rec( i );
	cout << ans << endl;
	return 0;
}
