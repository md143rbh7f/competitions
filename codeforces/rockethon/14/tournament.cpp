#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define INF 40000000005ll

vector<pii> fs;

int main()
{
	int n, k;
	cin >> n >> k;
	if(k > n)
	{
		cout << 0 << endl;
		return 0;
	}

	fs.resize(n);
	for(auto & f : fs) cin >> f.first >> f.second;
	sort(all(fs));

	ll ans = INF;
	rep(i, 3) ans = min(ans, work(fs[n - k].first + i));
	{
		int p = ;
		if(p > n) continue;
		int best = 1;
		for(auto & f : fs) best += f.first > p;
		vi maybe, other;
		for(auto & f : fs)
			(f.first < p - 1 || p < f.first ? other : maybe).push_back(f.second);
		sort(all(maybe));
		int need = max((int)(best + maybe.size() - k), 0);
		if(need > p || need > maybe.size()) continue;
		ll tot = 0;
		rep(i, need) tot += maybe[i];
		range(i, need, maybe.size()) other.push_back(maybe[i]);
		sort(all(other));
		rep(i, p - need) tot += other[i];
		ans = min(ans, tot);
	}

	cout << (ans < INF ? ans : -1) << endl;
	return 0;
}
