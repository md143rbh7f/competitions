#include <algorithm>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define acc(f,x,y) x=f(x,y)

#define S 10
#define INF 123456789

struct edge { int u, v, c; };

int d[1<<S][S*S+5];

struct FoxTheLinguist
{
	int minimalHours(int k, vs strs)
	{
		vector<edge> es;

		stringstream ss(accumulate(all(strs), string()));
		for(string e; ss >> e;)
			es.push_back({
				S * (e[0] - 'A') + e[1] - '0',
				S * (e[4] - 'A') + e[5] - '0',
				10 * (10 * (10 * (e[7] - '0') + e[8] - '0') + e[9] - '0') + e[10] - '0'
			});

		int n = S * k + 1;
		rep(s, 1<<k) rep(i, n) d[s][i] = INF;
		rep(i, k)
		{
			es.push_back({n - 1, S * i, 0});
			d[1<<i][S * i + 9] = 0;
			rep(j, S - 1)
				es.push_back({S * i + j + 1, S * i + j, 0});
		}

		// Steiner tree
		rep(s, 1<<k)
		{
			rep(i, n) for(int t = s; t; t = s & (t - 1))
				acc(min, d[s][i], d[t][i] + d[s^t][i]);
			rep(i, n) for(auto & e : es)
				acc(min, d[s][e.u], d[s][e.v] + e.c);
		}

		int ans = d[(1<<k) - 1][n - 1];
		return ans < INF ? ans : -1;
	}
};
