#include <vector>

using namespace std;

#define N 14

long long c[1<<N][N];
bool bad[N][N];

struct RandomOption
{
	double getProbability( int n, vector<int> a, vector<int> b )
	{
		for( int i = 0; i < a.size(); i++ ) bad[a[i]][b[i]] = bad[b[i]][a[i]] = true;

		for( int i = 0; i < n; i++ ) c[1<<i][i] = 1;

		for( int s = 0; s < 1<<n; s++ )
		for( int i = 0; i < n; i++ ) if( ( s >> i ) & 1 )
		for( int j = 0; j < n; j++ ) if( !( ( s >> j ) & 1 ) && !bad[i][j] )
			c[s^(1<<j)][j] += c[s][i];

		double ans = 0;
		for( int i = 0; i < n; i++ ) ans += c[(1<<n)-1][i];
		for( int i = 1; i <= n; i++ ) ans /= i;
		return ans;
	}
};
