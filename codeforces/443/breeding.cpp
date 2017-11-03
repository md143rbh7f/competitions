#include <algorithm>
#include <bitset>
#include <cstdio>
#include <utility>

using namespace std;

using pii = pair<int,int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define fst first
#define snd second

constexpr int N = 100005, K = 12;

pii cs[N][K];
bitset<1 << K> xs[N];

int main() {
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);

	rep (i, k) {
		rep (j, n) scanf("%d", &cs[j][i].fst), cs[j][i].snd = i;
		rep (s, 1 << k) xs[i][s] = (s >> i) & 1;
	}

	rep (j, n) sort(cs[j], cs[j] + k);

	int m = k, t, i, j;
	rep (_, q) {
		scanf("%d%d%d", &t, &i, &j);
		i--, j--;
		if (t == 1) xs[m++] = xs[i] & xs[j];
		else if (t == 2) xs[m++] = xs[i] | xs[j];
		else {
			int s = 0;
			for (auto c : cs[j]) {
				s |= 1 << c.snd;
				if (xs[i][s]) {
					printf("%d\n", c.fst);
					break;
				}
			}
		}
	}

	return 0;
}
