typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

constexpr int MOD = 1000000007, N = 2005, N2 = N*(N-1)/2;

int choose[N][N], pow2[N2], even[N], eulerian[N], ans[N];

void init() {
	rep(i, N) choose[i][0] = 1;
	range(i, 1, N) range(j, 1, i + 1)
		choose[i][j] = M(choose[i-1][j] + choose[i-1][j-1]);

	pow2[0] = 1;
	range(i, 1, N2)
		pow2[i] = M(pow2[i-1] * 2);

	even[0] = 1;
	range(i, 1, N)
		even[i] = pow2[choose[i-1][2]];

	rep(i, N) {
		eulerian[i] = even[i];
		range(j, 1, i) {
			int bad = M((ll) choose[i-1][j-1] * M((ll) eulerian[j] * even[i-j]));
			eulerian[i] = M(eulerian[i] + MOD - bad);
		}
	}
};

struct AlmostEulerianGraph {
int calculateGraphs(int n) {
	init();
	return M((ll) eulerian[n] * (1 + choose[n][2]));
}
};
