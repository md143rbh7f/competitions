#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

struct Group {
	int sz;
	vector<int> lo, hi;

	Group (int * a, int * b) : sz(1), lo(a, b), hi(a, b) {}

	bool operator<(const Group & o) const {
		rep (i, hi.size()) if (hi[i] >= o.lo[i]) return false;
		return true;
	}

	void merge(const Group & o) {
		sz += o.sz;
		rep (i, lo.size()) {
			lo[i] = min(lo[i], o.lo[i]);
			hi[i] = max(hi[i], o.hi[i]);
		}
	}
};

int main() {
	int n, k, s[10];
	scanf("%d%d", &n, &k);

	set<Group> grps;
	rep (_, n) {
		rep (i, k) scanf("%d", s + i);
		Group grp(s, s + k);
		auto i0 = grps.lower_bound(grp), i1 = grps.upper_bound(grp);
		while (i0 != i1) {
			grp.merge(*i0);
			i0 = grps.erase(i0);
		}
		grps.insert(i0, grp);
		printf("%d\n", grps.rbegin()->sz);
	}

	return 0;
}
