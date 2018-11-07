#include <cstdio>
#include <map>
#include <utility>
#include <vector>

using namespace std;

using vi = vector<int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

int main() {
	int n;
	scanf("%d", &n);
	map<int, int> c, f;
	map<int, vi> grp;
	int last = 0, t, l, r, x;
	rep (i, n) {
		if (last == -1) last = 1;
		scanf("%d%d%d", &t, &l, &r);
		l ^= last, r ^= last;
		if (l > r) swap(l, r);
		r++;
		if (t == 1) {
			scanf("%d", &x);
			x ^= last;

			if (!c.count(l) && !c.count(r)) {
				grp[c[l] = c[r] = l] = {l, r};
				f[l] = 0, f[r] = x;
			} else if (!c.count(r)) {
				grp[c[r] = c[l]].push_back(r);
				f[r] = f[l] ^ x;
			} else if (!c.count(l)) {
				grp[c[l] = c[r]].push_back(l);
				f[l] = f[r] ^ x;
			} else if (c[l] != c[r]) {
				if (grp[c[l]].size() > grp[c[r]].size()) swap(l, r);
				auto &gl = grp[c[l]], &gr = grp[c[r]];
				int delta = f[l] ^ f[r] ^ x;
				for (auto &m : gl) {
					gr.push_back(m);
					c[m] = c[r];
					f[m] ^= delta;
				}
			}
		} else {
			last = c.count(l) && c.count(r) && c[l] == c[r] ? f[l] ^ f[r] : -1;
			printf("%d\n", last);
		}
	}
	return 0;
}
