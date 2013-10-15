#include <cstring>

using namespace std;

typedef long long ll;

#define N 55
#define K 666

int need;
ll mem[N][N][K];

ll rec(int n, int used, int score)
{
	ll & ans = mem[n][used][score];
	if(ans != -1) return ans;
	if(!n) return ans = score >= need;
	int free = n - used;
	ans = 0;
	#define acc(x) ans = (ans + x)%1000000007
	if(free >= 1) acc(free * (2 * used + 1) * rec(n - 1, used, score));
	if(free >= 2) acc(free * (free - 1) * rec(n - 1, used + 1, score + n));
	if(used >= 1) acc(used * used * rec(n - 1, used - 1, score - n));
	return ans;
}

struct LittleElephantAndPermutationDiv1
{
	int getNumber(int n, int k)
	{
		need = k - n * (n + 1) / 2;
		memset(mem, -1, sizeof(mem));
		return rec(n, 0, 0);
	}
};
