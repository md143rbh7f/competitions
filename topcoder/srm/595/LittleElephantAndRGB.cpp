#include <numeric>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define N 2505

string s;
int n, need, pre[N][N];

void precompute()
{
	rep(a,n)
	{
		int g = 0;
		range(b, a, n)
		{
			if(g == need);
			else if(s[b] == 'G') g++;
			else g = 0;
			pre[b][g]++;
		}
	}
	range(b, 1, n) rep(g, need + 1)
		pre[b][g] += pre[b-1][g];
	rep(b, n) for(int g = need; g; g--)
		pre[b][g-1] += pre[b][g];
}

ll run()
{
	ll ans = 0;
	range(c, 1, n)
	{
		int g = 0, h = 0;
		bool start = true;
		range(d, c, n)
		{
			if(g == need);
			else if(s[d] == 'G')
			{
				g += start, h++;
				if(h >= need) g = need;
			}
			else h = 0, start = false;
			ans += pre[c-1][need-g];
		}
	}
	return ans;
}

struct LittleElephantAndRGB
{
	ll getNumber(vs _s, int _need)
	{
		s = accumulate(all(_s), string());
		n = s.size();
		need = _need;
		precompute();
		return run();
	}
};
