#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;
#define all(c) begin(c),end(c)

#define INF 1e13

unordered_map<ll, deque<ll>> _divisors;

deque<ll> & divisors(ll n)
{
	auto & ans = _divisors[n];
	if(ans.size()) return ans;
	ll x = 2;
	for(; x * x < n; x++) if(!(n % x)) ans.push_back(x), ans.push_back(n / x);
	if(x * x == n) ans.push_back(x);
	ans.push_back(INF);
	sort(all(ans));
	return ans;
}

ll get(ll n, ll h)
{
	auto & q = divisors(n);
	while(q.front() < h) q.pop_front();
	return q.front();
}

struct Procrastination
{
ll findFinalAssignee(ll n)
{
	if(n < 4) return n;
	ll h = 2;
	while(true)
	{
		ll lo = get(n - 1, h), hi = get(n, h);
		if(lo == INF && hi == INF) break;
		if(lo < hi) n--, h = lo + 1;
		else n++, h = hi + 1;
	}
	return n;
}
};
