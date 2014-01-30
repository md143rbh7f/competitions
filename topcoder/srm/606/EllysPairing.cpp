#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

struct EllysPairing
{
	int getMax(int m, vi cnt, vi fst, vi mul, vi add)
	{
		m--;
		int n = cnt.size(), sz = 0, freq = 1, maj = -1;
		unsigned int x, t, a;
		rep(i, n)
		{
			sz += cnt[i], x = fst[i], t = mul[i], a = add[i];
			rep(j, cnt[i])
			{
				if(x == maj) freq++;
				else freq--;
				if(!freq) maj = x, freq = 1;
				x = (t * x + a) & m;
			}
		}
		freq = 0;
		rep(i, n)
		{
			x = fst[i], t = mul[i], a = add[i];
			rep(j, cnt[i])
			{
				if(x == maj) freq++;
				x = (t * x + a) & m;
			}
		}
		return 2 * freq > sz ? sz - freq : sz / 2;
	}
};
