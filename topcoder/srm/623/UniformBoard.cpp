#include <algorithm>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

struct UniformBoard
{
int getBoard(vs b, int k)
{
	int n = b.size(), tot = 0;
	bool can = false;
	rep(i, n) rep(j, n)
	{
		can |= b[i][j] == '.';
		tot += b[i][j] == 'A';
	}
	k *= can;

	int best = 0;
	rep(i0, n) rep(j0, n) range(i1, i0, n) range(j1, j0, n)
	{
		int p = 0, q = 0, s = (i1 - i0 + 1) * (j1 - j0 + 1);
		if(tot < s) continue;
		range(i, i0, i1 + 1) range(j, j0, j1 + 1)
		{
			p += b[i][j] == 'P';
			q += b[i][j] != 'A';
		}
		if(q + p <= k) best = max(best, s);
	}

	return best;
}
};
