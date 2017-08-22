#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define M(x) ((x)%MOD)

constexpr int MOD = 1000000007;

ll mod_pow(ll a, ll b) {
	if (!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

struct SubtreeSumHash {
int count(vi w, vi p, int x) {
	int n = w.size();
	vll h(n);
	ll ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		h[i] = mod_pow(x, w[i]);
		range (j, i + 1, n) if (p[j - 1] == i) {
			h[i] = M(h[i] * (h[j] + 1));
		}
		ans = M(ans + h[i]);
	}

	return ans;
}
};
