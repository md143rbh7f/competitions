#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

bool used[55];

struct TeamContest
{
	int worstRank(vi s)
	{
		sort(s.begin(), s.begin() + 3), sort(s.begin() + 3, s.end());
		used[0] = used[1] = used[2] = true;
		int n = s.size(), have = s[0] + s[2], t = 1;
		for(; ; t++)
		{
			int k = -1;
			rep(i, n - t - 1)
			if(!used[i] && !used[i + 1] && s[n - t] + s[i] > have && (k == -1 || s[i] < s[k]))
				k = i;
			if(k == -1) break;
			used[n - t] = used[k] = used[k + 1] = true;
		}
		return t;
	}
};
