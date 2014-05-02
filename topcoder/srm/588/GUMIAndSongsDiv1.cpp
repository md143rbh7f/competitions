#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define acc(f,x,y) x=f(x,y)

int INF = 12345678;

struct GUMIAndSongsDiv1
{
	int maxSongs(vi duration, vi tone, int T)
	{
		int n = duration.size();
		vector<pii> info;
		rep(i, n) info.push_back({tone[i], duration[i]});
		sort(all(info));

		vector<vi> best(n + 1, vi(n + 1, INF));
		rep(i, n) best[0][i] = 0;
		rep(i, n) for(int j = i; j >= 0; j--) rep(k, i + 1)
			acc(min, best[j+1][i], best[j][k] - info[k].first + info[i].first + info[i].second);

		int ans = 0;
		rep(i, n + 1) rep(j, n) if(best[i][j] <= T) acc(max, ans, i);

		return ans;
	}
};
