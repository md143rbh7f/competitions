#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

#define MAX 100001

long long dp[2][MAX];
pair<double,int> p[50];

struct TheProgrammingContestDivOne
{
	int find( int T, vector<int> maxpts, vector<int> ppm, vector<int> rtime )
	{
		int n = maxpts.size();
		for( int i = 0; i < n; i++ ) p[i] = make_pair( 1.0 * rtime[i] / ppm[i], i );
		sort(p,p+n);
		for( int I = 0; I < n; I++ )
		{
			int id = p[I].second, i = I%2;
			long long cur = maxpts[id];
			for( int t = 1; t <= T; t++ )
			{
				cur -= ppm[id];
				dp[i][t] = max( dp[1-i][t], dp[i][t-1] );
				if( t >= rtime[id] ) dp[i][t] = max( dp[i][t], dp[1-i][t-rtime[id]] + cur );
			}
		}
		return dp[(n-1)%2][T];
	}
};
