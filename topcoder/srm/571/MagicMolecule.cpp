#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define M 1225

int n, m, s, k, a[M], b[M];
bool del[M];
vi p;

int f(int e)
{
	if(3 * k < 2 * n) return -1;
	if(e == m) return s;
	if(del[a[e]] || del[b[e]]) return f(e + 1);
	k--, s -= p[a[e]], del[a[e]] = true;
	int x = f(e + 1);
	s += p[a[e]] - p[b[e]], del[a[e]] = false, del[b[e]] = true;
	int y = f(e + 1);
	k++, s += p[b[e]], del[b[e]] = false;
	return max(x, y);
}

struct MagicMolecule
{
	int maxMagicPower(vi _p, vs g)
	{
		p = _p, k = n = p.size();
		rep(i, n) s += p[i];
		rep(i, n) range(j, i + 1, n) if(g[i][j] == 'N')
			a[m] = i, b[m] = j, m++;
		return f(0);
	}
};
