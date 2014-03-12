#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)

#define N 20

int n;
double d[N][N], inf = 7777777;
bool seen[N];

inline double sq(double x) { return x * x; }

double work(double m)
{
	clr(seen);
	vector<double> used;
	set<pair<double, pair<double,int>>> q;
	seen[0] = true;
	rep(i, n) q.insert({sq(d[0][i] - m), {d[0][i], i}});
	while(!q.empty())
	{
		auto pt = q.begin();
		double len = pt->second.first;
		int u = pt->second.second;
		q.erase(pt);
		if(seen[u]) continue;
		seen[u] = true;
		used.push_back(len);
		rep(v, n) q.insert({sq(d[u][v] - m), {d[u][v], v}});
	}
	double mean = accumulate(all(used), 0.0) / (n - 1), tot = 0;
	for(auto len : used) tot += sq(len - mean);
	return sqrt(tot / (n - 1));
}

struct Egalitarianism2
{
	double minStdev(vi x, vi y)
	{
		n = x.size();
		rep(i, n) rep(j, n) d[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
		set<double> mids;
		rep(i, n) rep(j, n) rep(k, n) rep(l, n)
			mids.insert((d[i][j] + d[k][l]) / 2);
		mids.insert(inf);
		double last = 0, ans = inf;
		for(auto & x : mids) ans = min(ans, work((x + last) / 2)), last = x;
		return ans;
	}
};
