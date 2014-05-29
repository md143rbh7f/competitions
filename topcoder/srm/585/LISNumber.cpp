#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

#define N 55
#define K 1300
#define MOD 1000000007

ll ans[N][K], choose[K][K];

struct LISNumber
{
	int count(vi c, int k)
	{
		rep(i, K) choose[i][0] = 1;
		range(i, 1, K) range(j, 1, i + 1)
			choose[i][j] = M(choose[i-1][j] + choose[i-1][j-1]);

		int n = c.size(), s = 0;
		ans[0][0] = 1;
		rep(i, n)
		{
			rep(j, k + 1) if(ans[i][j]) rep(x, c[i] + 1)
				ans[i + 1][j + c[i] - x] = M(ans[i + 1][j + c[i] - x] + M(M(choose[j][x] * choose[s + c[i] - j][c[i] - x]) * ans[i][j]));
			s += c[i];
		}

		return ans[n][k];
	}
};
