#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

pair<int,int> c[100005];

int main()
{
	int n, k;
	long long b;
	cin >> n >> k >> b;
	for( int i = 0; i < n; i++ )
	{
		cin >> c[i].first;
		c[i].second = i + 1;
	}
	sort( c, c + n - 1 );
	reverse( c, c + n - 1 );

	long long tot = 0;
	for( int i = 0; i < k - 1; i++ ) tot += c[i].first;
	
	int best = n;
	for( int i = 0; i < n - 1; i++ )
	{
		bool ok = b - tot < c[ max( k - 1, i ) ].first;
		if( ok && c[i].second < best ) best = c[i].second;
	}
	cout << best << endl;

	return 0;
}
