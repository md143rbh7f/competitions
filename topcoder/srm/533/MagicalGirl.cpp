#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#include <iostream>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define N 55
#define MAX 100005
#define INF 123456789

double dp[2][MAX]; // day, health
int d[N];
vector<double> p[N];
vector<int> g[N];
map< int, vector< pair<double,int> > > tmp;

struct MagicalGirl
{
	double maxExpectation( int M, vector<int> D, vector<int> P, vector<int> G )
	{
		for( int i = 0; i < D.size(); i++ ) tmp[D[i]].push_back( make_pair( 0.01 * P[i], G[i] ) );
		tmp[0].push_back( make_pair( 1, 0 ) );
		int I = 0, n = tmp.size();
		foreach(it,tmp)
		{
			d[I] = it->first;
			for( int i = 0; i < it->second.size(); i++ )
			{
				p[I].push_back( it->second[i].first );
				g[I].push_back( it->second[i].second );
			}
			I++;
		}
		d[n] = INF;
		I = n%2;
		for( int i = n-1; i >= 0; i-- )
		{
			I = 1-I;
			int diff = d[i+1]-d[i];
			for( int j = 1; j <= M; j++ )
				dp[I][j] = j > diff ? diff + dp[1-I][j-diff] : j;
			for( int k = 0; k < p[i].size(); k++ ) for( int j = 1; j <= M; j++ )
				dp[I][j] = max( dp[I][j], p[i][k] * dp[I][ min( j + g[i][k], M ) ] );
		}
		return dp[0][M];
	}
};
