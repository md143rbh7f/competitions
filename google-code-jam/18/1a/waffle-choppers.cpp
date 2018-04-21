#include <cstdio>
#include <cstring>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

constexpr int N = 105;

char buf[N];
int s[N][N], hs[N], vs[N];

inline int rect(int r0, int c0, int r1, int c1) {
	return s[r1][c1] - s[r0][c1] - s[r1][c0] + s[r0][c0];
}

bool work() {
	clr0(buf), clr0(s);

	int r, c, h, v;
	scanf("%d%d%d%d", &r, &c, &h, &v);
	h++, v++;

	rep (i, r) {
		scanf("%s", buf);
		rep (j, c)
			s[i + 1][j + 1] =
				s[i + 1][j] + s[i][j + 1] - s[i][j] + (buf[j] == '@');
	}

	int tot = s[r][c], per_h = tot / h, per_v = tot / v, per = tot / h / v;
	if (tot != per * h * v) return false;

	int *he = hs, *ve = vs;
	rep (i, r + 1) if (rect(*he, 0, i, c) == per_h) {
		*(++he) = i;
		if (he - hs == h) {
			*(++he) = r;
			break;
		}
	}
	if (*he != r) return false;

	rep (j, c + 1) if (rect(0, *ve, r, j) == per_v) {
		*(++ve) = j;
		if (ve - vs == v) {
			*(++ve) = c;
			break;
		}
	}
	if (*ve != c) return false;

	rep (i, h) rep (j, v)
		if (rect(hs[i], vs[j], hs[i + 1], vs[j + 1]) != per)
			return false;

	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) printf("Case #%d: %sPOSSIBLE\n", i + 1, work() ? "" : "IM");
	return 0;
}
