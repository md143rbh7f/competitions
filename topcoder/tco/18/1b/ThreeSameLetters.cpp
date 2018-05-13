#include <utility>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

constexpr int C = 26, MOD = 1000000007;

int cnt[2][C][C][2];

struct ThreeSameLetters {
int countStrings(int n, int c) {
	auto cur = cnt[0], nxt = cnt[1];
	rep (i, c) rep (j, c) cur[i][j][0] = 1;
	range (_, 2, n) {
		rep (i, c) rep (j, c) {
			rep (k, c) {
				if (i == j && j == k)
					nxt[j][k][1] = M(nxt[j][k][1] + cur[i][j][0]);
				else rep (l, 2)
					nxt[j][k][l] = M(nxt[j][k][l] + cur[i][j][l]);
			}
			rep (l, 2) cur[i][j][l] = 0;
		}
		swap(cur, nxt);
	}
	int ans = 0;
	rep (i, c) rep (j, c) ans = M(ans + cur[i][j][1]);
	return ans;
}
};
