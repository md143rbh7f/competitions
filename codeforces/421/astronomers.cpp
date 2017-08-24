#include <algorithm>
#include <cstdio>
#include <map>
#include <tuple>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define fst first
#define snd second
#define tup make_tuple

constexpr int N = 200005;

int xs[N], ans[N];

void extended_euclidean(int a, int b, int & lx, int & ly) {
	int x = 0, y = 1;
	lx = 1, ly = 0;
	while (b) {
		int q = a / b;
		tie(a, b) = tup(b, a % b);
		tie(x, lx) = tup(lx - q * x, x);
		tie(y, ly) = tup(ly - q * y, y);
	}
}

int mod_inv(int a, int m) {
	int lx, ly;
	extended_euclidean(a, m, lx, ly);
	if (lx < 0) lx += m;
	return lx;
}

int main() {
	int t, n;
	scanf("%d%d", &t, &n);

	int s = 0;
	rep (i, n) {
		int tmp;
		scanf("%d", &tmp);
		s = (s + tmp) % t;
		if (i > 0) xs[i] = (xs[i - 1] + tmp) % t;
	}

	int g = __gcd(s, t), q = t / g, s_inv = mod_inv(s / g, q);
	unordered_map<int, map<int, int>> cosets;
	rep (i, n) {
		map<int, int> & coset = cosets[xs[i] % g];
		int pos = (ll) s_inv * (xs[i] / g) % q;
		if (!coset.count(pos)) coset[pos] = i;
	}

	for (auto & _ : cosets) {
		map<int, int> & coset = _.snd;
		pii prev = *coset.rbegin();
		prev.fst -= q;
		for (auto & cur : coset) {
			ans[prev.snd] = cur.fst - prev.fst;
			prev = cur;
		}
	}

	rep (i, n) printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
