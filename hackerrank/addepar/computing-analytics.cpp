#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005

set<int> s[N];
map<pii,bool> ans;

bool work(int x, int y)
{
	if(ans.count({x, y})) return ans[{x, y}];
	bool & ok = ans[{x, y}];
	ok = s[x].count(y);
	if(!ok)
	{
		if(s[x].size() > s[y].size()) swap(x, y);
		for(auto z : s[x]) if(s[y].count(z))
			return ok = true;
	}
	return ok;
}

int main()
{
	int n, c, q;
	scanf("%d%d%d", &n, &c, &q);
	rep(i, c)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		s[x - 1].insert(y), s[y].insert(x - 1);
	}
	rep(i, q)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf(work(x - 1, y) ? "YES\n" : "NO\n");
	}
	return 0;
}
