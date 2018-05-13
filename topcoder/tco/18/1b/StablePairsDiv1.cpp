#include <algorithm>
#include <vector>

using namespace std;

using vi = vector<int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

struct StablePairsDiv1 {
vi findMaxStablePairs(int n, int c, int k) {
	if (k == 1) {
		if (n > 1) return {n - 1, n};
		return {};
	}
	if (c < 4) return {};
	vi ans;
	bool bump = false;
	int y = n, step = (c - 2) / 2;
	rep (_, k) {
		ans.push_back(y);
		int x = y - 1 - bump;
		if (x <= 0) return {};
		ans.push_back(x);
		y = x - step;
		bump ^= c & 1;
	}
	reverse(all(ans));
	return ans;
}
};
