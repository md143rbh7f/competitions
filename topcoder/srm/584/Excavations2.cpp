#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 55

ll choose[N][N], cnt[N];

struct Excavations2
{
	ll count(vi kind, vi found, int k)
	{
		rep(i, N) choose[i][0] = 1;
		range(i, 1, N) range(j, 1, i + 1)
			choose[i][j] = choose[i-1][j] + choose[i-1][j-1];

		cnt[0] = 1;
		for(auto t : found)
		{
			int have = 0;
			for(auto k : kind) have += k == t;
			for(int i = N - 1; i >= 0; i--) if(cnt[i])
			{
				range(j, 1, have + 1)
					cnt[i + j] += cnt[i] * choose[have][j];
				cnt[i] = 0;
			}
		}
		return cnt[k];
	}
};
