typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

#define MOD 1000000009
#define N 1005
#define C 26

ll f[C+1], c[N][N];

struct StringWeightDiv2
{
	int countMinimums(int n)
	{
		f[0] = 1;
		range(i, 1, C + 1) f[i] = M(i * f[i-1]);
		rep(i, N) c[i][0] = 1;
		range(i, 1, N) range(j, 1, i + 1)
			c[i][j] = M(c[i-1][j] + c[i-1][j-1]);
		return M(n < C ? c[C][n] * f[n] : c[n-1][C-1] * f[C]);
	}
};
