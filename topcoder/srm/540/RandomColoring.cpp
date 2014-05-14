#include <algorithm>
#include <cstdlib>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 55

double p[N][N][N], f[N][N][N];
int R, G, B, sz[N][N][N];

double get(int r, int g, int b, int d)
{
	if(d < 0) return 0;
	int r0 = max(r - d, 0), r1 = min(r + d + 1, R);
	int g0 = max(g - d, 0), g1 = min(g + d + 1, G);
	int b0 = max(b - d, 0), b1 = min(b + d + 1, B);
	return
		f[r1][g1][b1]
		- f[r0][g1][b1] - f[r1][g0][b1] - f[r1][g1][b0]
		+ f[r1][g0][b0] + f[r0][g1][b0] + f[r0][g0][b1]
		- f[r0][g0][b0]
	;
}

struct RandomColoring
{
	double getProbability(int T, int _R, int _G, int _B, int r0, int g0, int b0, int d0, int d1)
	{
		R = _R, G = _G, B = _B;

		rep(r, R) rep(g, G) rep(b, B)
			sz[r][g][b] =
				(min(r + d1 + 1, R) - max(r - d1, 0)) *
				(min(g + d1 + 1, G) - max(g - d1, 0)) *
				(min(b + d1 + 1, B) - max(b - d1, 0))
				- 
				max(min(r + d0, R) - max(r - d0 + 1, 0), 0) *
				max(min(g + d0, G) - max(g - d0 + 1, 0), 0) *
				max(min(b + d0, B) - max(b - d0 + 1, 0), 0)
				;

		p[r0][g0][b0] = 1;

		rep(t, T - 1)
		{
			rep(r, R) rep(g, G) rep(b, B) if(sz[r][g][b])
				f[r + 1][g + 1][b + 1] =
					p[r][g][b] / sz[r][g][b]
					+ f[r][g + 1][b + 1] + f[r + 1][g][b + 1] + f[r + 1][g + 1][b]
					- f[r + 1][g][b] - f[r][g + 1][b] - f[r][g][b + 1]
					+ f[r][g][b]
				;
			rep(r, R) rep(g, G) rep(b, B)
				p[r][g][b] = get(r, g, b, d1) - get(r, g, b, d0 - 1);
		}

		double ans = 0;
		rep(r, R) rep(g, G) rep(b, B)
			if(
				abs(r - r0) > d1 || abs(g - g0) > d1 || abs(b - b0) > d1
				|| (abs(r - r0) < d0 && abs(g - g0) < d0 && abs(b - b0) < d0)
			)
				ans += p[r][g][b];
		return ans;
	}
};
