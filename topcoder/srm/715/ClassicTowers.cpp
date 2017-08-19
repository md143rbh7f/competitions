#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)

constexpr int N = 55;

int p[N][N][N][3];

struct ClassicTowers {
string findTowers(long long t, vi goal) {
	int a = goal[0], b = goal[1], c = goal[2], n = a + b + c;
	if (t >= 1ll << (n - 1)) {
		return "";
	}

	clr1(p);
	p[0][0][0][0] = 0;
	p[0][0][0][1] = 0;
	p[0][0][0][2] = 0;

	int x[3], &i = x[0], &j = x[1], &k = x[2];
	for (i = 0; i <= a; i++)
	for (j = 0; j <= b; j++)
	for (k = 0; k <= c; k++)
	rep (want, 3)
	if (p[i][j][k][want] >= 0) {
		bool diff = 1 & (t >> (n - 1 - i - j - k));
		rep (pos, 3) if (diff ^ (pos == want)) {
			x[pos]++;
			p[i][j][k][pos ^ (diff * (3 ^ want))] = pos;
			x[pos]--;
		}
	}

	i = a, j = b, k = c;
	rep (want, 3)
	if (p[i][j][k][want] >= 0) {
		string ans(n, 'A');
		rep (m, n) {
			int pos = p[i][j][k][want];
			ans[m] += pos;
			x[pos]--;
			want ^= (want != pos) * (3 ^ pos);
		}
		return ans;
	}

	return "";
}
};
