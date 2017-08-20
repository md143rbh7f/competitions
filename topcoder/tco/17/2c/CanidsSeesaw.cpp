#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define fst first
#define snd second

constexpr int N = 55;

bool used[N];
pii perm[N];

int score(vi & xs) {
	int xt = 0, yt = 0, ans = 0;
	rep (i, xs.size()) {
		xt += xs[i];
		yt += perm[i].fst;
		ans += yt > xt;
	}
	return ans;
}

struct CanidsSeesaw {
vi construct(vi xs, vi ys, int need) {
	int n = xs.size();

	vector<pii> ps;
	rep (i, n) ps.emplace_back(ys[i], i);
	sort(all(ps));

	rep (i, n) {
		pii good {-1, -1};
		rep (j, n) {
			if (!used[ps[j].snd]) {
				perm[i] = ps[j];
				used[ps[j].snd] = true;

				int k = i + 1;
				rep (l, n) if (!used[ps[l].snd])
					perm[k++] = ps[l];
				if (score(xs) <= need)
					good = ps[j];

				used[ps[j].snd] = false;
			}
		}

		if (good.fst == -1)
			return {};

		perm[i] = good;
		used[good.snd] = true;
	}

	if (score(xs) == need) {
		vi ans;
		rep (i, n) ans.push_back(perm[i].snd);
		return ans;
	}
	return {};
}
};
