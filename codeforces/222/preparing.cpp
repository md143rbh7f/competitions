#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define lvl first
#define id second

#define N 100005

int ns, nb, nc, ans[N], c[N];
pii ss[N], bs[N];

bool work(int d)
{
	ll tc = 0;
	set<pii> can;
	int s = 0, b = 0;
	while(b < nb)
	{
		for(; s < ns && ss[s].lvl >= bs[b].lvl; s++) can.insert({c[ss[s].id], ss[s].id});
		if(can.empty()) return false;
		pii best = *can.begin();
		can.erase(can.begin());
		tc += best.first;
		for(int k = 0; k < d && b < nb; k++) ans[bs[b++].id] = best.second;
	}
	return tc <= nc;
}

int main()
{
	cin >> ns >> nb >> nc;
	rep(b, nb) cin >> bs[b].lvl, bs[b].id = b;
	rep(s, ns) cin >> ss[s].lvl, ss[s].id = s;
	rep(s, ns) cin >> c[s];
	sort(ss, ss + ns, greater<pii>()), sort(bs, bs + nb, greater<pii>());

	int l = 1, r = nb + 1;
	while(l < r)
	{
		int m = (l + r) / 2;
		if(work(m)) r = m;
		else l = m + 1;
	}
	if(l == nb + 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;

	work(l);
	rep(b, nb) cout << ans[b] + 1 << " ";
	cout << endl;
	return 0;
}
