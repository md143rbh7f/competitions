#include <vector>

using namespace std;

#define N 55

vector<int> g[N];
int len[N];
double p[N];

void dfs( int v, int l )
{
	len[v] = l;
	for( int i = 0; i < g[v].size(); i++ ) dfs( g[v][i], l+1 );
}

struct PrinceXToastbook
{
	double eat( vector<int> parent )
	{
		p[0] = 1;
		for( int i = 1; i < N; i++ ) p[i] = p[i-1] / i;

		int n = parent.size();
		for( int i = 0; i < n; i++ ) g[ parent[i] > -1 ? parent[i] : n ].push_back(i);
		dfs( n, 0 );

		double ans = 0;
		for( int i = 0; i < n; i++ ) if( len[i] ) ans += p[len[i]];
		return ans;
	}
};
