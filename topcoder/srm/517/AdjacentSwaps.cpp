#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)
#define M(x) ((x)%MOD)

#define N 55
#define MOD 1000000007

int p[N];
ll choose[N][N], mem[N][N];

ll rec(int a, int b)
{
	ll & ans = mem[a][b];
	if(ans != -1) return ans;
	if(b - a == 1) return ans = 1;
	ans = 0;
	range(c, a + 1, b)
	{
		swap(p[c - 1], p[c]);
		int x = *max_element(p + a, p + c), y = *min_element(p + c, p + b);
		if(y > x)
			ans = M(ans + M(choose[b-a-2][c-a-1] * M(rec(a, c) * rec(c, b))));
		swap(p[c - 1], p[c]);
	}
	return ans;
}

struct AdjacentSwaps
{
	int theCount(vi _p)
	{
		rep(i, N) choose[i][0] = 1;
		range(i, 1, N) range(j, 1, i + 1)
			choose[i][j] = M(choose[i-1][j] + choose[i-1][j-1]);
		int n = _p.size();
		rep(i, n) p[i] = _p[i];
		clr1(mem);
		return rec(0, n);
	}
};
