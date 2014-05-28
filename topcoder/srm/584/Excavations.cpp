#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define N 55

ll choose[N][N], ways[N][N][N];
int cnt[N];

struct Excavations
{
	ll count(vi kind, vi depth, vi found, int k)
	{
		rep(i, N) choose[i][0] = 1;
		range(i, 1, N) range(j, 1, i + 1)
			choose[i][j] = choose[i-1][j] + choose[i-1][j-1];

		int n = kind.size(), m = 0, p = found.size();

		map<int, int> id;
		for(auto d : depth) id[d] = 0;
		for(auto & p : id) p.second = m++;
		for(auto & d : depth) d = id[d];

		ways[0][0][0] = 1;
		rep(t, p)
		{
			vi ds;
			rep(i, n) if(kind[i] == found[t])
				ds.push_back(depth[i]);
			sort(all(ds));
			rep(d, m) rep(i, n) if(ways[t][d][i]) rep(j, ds.size())
				ways[t + 1][max(d, ds[j])][i + ds.size() - j - 1] += ways[t][d][i];
		}

		set<int> ok(all(found));
		rep(i, n) if(!ok.count(kind[i]))
			cnt[depth[i]]++;
		for(int d = m - 1; d >= 0; d--)
			cnt[d] += cnt[d + 1];

		ll ans = 0;
		rep(d, m) rep(i, n) if(ways[p][d][i])
			ans += ways[p][d][i] * choose[i + cnt[d + 1]][k - p];
		return ans;
	}
};
