#include <iostream>
#include <string>

using namespace std;

#define N 5005
#define MOD 1000000007

string s, t;
long long ways[N][N];

int main()
{
	cin >> s >> t;
	for( int i = 0; i < t.size(); i++ ) for( int j = 0; j < s.size(); j++ )
		ways[i+1][j+1] = ( ways[i][j+1] + ( t[i] == s[j] ? 1 + ways[i][j] : 0 ) ) % MOD;
	long long ans = 0;
	for( int j = 1; j <= s.size(); j++ ) ans = ( ans + ways[t.size()][j] ) % MOD;
	cout << ans << endl;
	return 0;
}
