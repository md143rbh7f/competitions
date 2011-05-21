#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef long long ll;
#define MAX 10000

int T, n, m, cost[MAX];
string d[MAX], strat;
map<ll,bool> has[11];
ll coset[MAX];
bool contains[MAX][26];

int main()
{
	cin >> T;
	for( int t = 1; t <= T; t++ )
	{
		cin >> n >> m;
		for( int i = 0; i < n; i++ )
		{
			cin >> d[i];
			for( int j = 0; j < 26; j++ ) contains[i][j] = false;
			for( int j = 0; j < d[i].size(); j++ ) contains[i][d[i][j]-'a'] = true;
		}
		cout << "Case #" << t << ":";
		for( int i = 0; i < m; i++ )
		{
			for( int j = 0; j < n; j++ ) coset[j] = cost[j] = 0;
			cin >> strat;
			for( int J = 0; J < 26; J++ )
			{
				int j = J%2;
				for( int k = 1; k <= 10; k++ ) has[k].clear();
				for( int k = 0; k < n; k++ ) if( contains[k][strat[J]-'a'] ) has[d[k].size()][coset[k]] = true;
				for( int k = 0; k < n; k++ ) if( has[d[k].size()][coset[k]] )
				{
					if( contains[k][strat[J]-'a'] )
					{
						ll pow = 1;
						for( int l = 0; l < d[k].size(); l++ )
						{
							if( d[k][l] == strat[J] ) coset[k] += (strat[J]-'a'+1)*pow;
							pow *= 27;
						}
					}
					else cost[k]++;
				}
			}
			int best = 0;
			for( int j = 0; j < n; j++ ) if( cost[j] > cost[best] ) best = j;
			cout << " " << d[best];
		}
		cout << endl;
	}
	return 0;
}
