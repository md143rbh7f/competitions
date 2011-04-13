#include <algorithm>
#include <iostream>

using namespace std;

long long ans = 1;
int d[3], k, x;

int main()
{
	for( int i = 0; i < 3; i++ ) cin >> d[i];
	sort( d, d+3 );
	cin >> k;
	for( int i = 0; i < 3; i++ )
	{
		x = min( d[i] - 1, ( k + 2 - i ) / ( 3 - i ) );
		k -= x;
		ans *= x + 1;
	}
	cout << ans << endl;
	return 0;
}
