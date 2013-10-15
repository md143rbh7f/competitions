#include <vector>

using namespace std;

typedef vector<int> vi;
#define iter(i,a,b,c) for(auto i=(a);i c(b);i++)
#define range(i,a,b) iter(i,a,b,<)
#define rep(i,n) range(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define N 55
#define M 500005

bool ok[M];

struct MayTheBestPetWin
{
	int calc(vi xs, vi ys)
	{
		vi zs;
		int n = xs.size(), s = 0, t = 0;
		rep(i,n) s += xs[i], t += ys[i], zs.push_back(xs[i] + ys[i]);
		ok[0] = true;
		for(auto z : zs) for(int i = t; i >= z; i--) ok[i] |= ok[i-z];
		int ans = t;
		rep(i,t+1) if(ok[i]) acc(min, ans, max(i-s, t-i));
		return ans;
	}
};
