#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 1005

int id[N];

struct LittleElephantAndIntervalsDiv1
{
	ll getNumber(int n, vi l, vi r)
	{
		int m = l.size();
		rep(i, m) range(j, l[i] - 1, r[i]) id[j] = i + 1;
		set<int> uniq(id, id+n);
		uniq.erase(0);
		return 1ll << uniq.size();
	}
};
