#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
#define M(x) ((x)%MOD)
#define MOD 1000000007

map<int,int> mem;

ll mod_pow(ll a, int b)
{
	if(!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

int cnt(int n, int k, int lo, int hi)
{
	if(mem.count(k)) return mem[k];
	int sz = hi - lo, del = 0, i;
	for(i = 2; i < sz; i++) del = M(del + cnt(n, i * k, lo / i, hi / i));
	for(i = max(i, lo + 1); i <= hi; i++) del++;
	return mem[k] = M(mod_pow(sz, n) + MOD - del);
}

struct RandomGCD
{
	int countTuples(int n, int k, int lo, int hi)
	{
		return cnt(n, k, (lo - 1) / k, hi / k);
	}
};
