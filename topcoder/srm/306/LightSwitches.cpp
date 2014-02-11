#include <bitset>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 50

inline bool zero(bool x) { return !x; }
template <size_t SZ>
void normalise(bitset<SZ> & v, int j) {}
template <size_t SZ>
void zero_out(bitset<SZ> & v, bitset<SZ> & u, int j) { if(u[j]) u ^= v; }

template <typename T>
int rref(vector<T> & a, int m = 0)
{
	int n = a.size(), r = 0;
	if(!m) m = a[0].size();
	rep(j, m)
	{
		bool found = false;
		range(i, r, n) if(!zero(a[i][j]))
		{
			found = true;
			swap(a[r], a[i]);
			break;
		}
		if(!found) continue;
		normalise(a[r], j);
		rep(i, n) if(!zero(a[i][j]) && i != r) zero_out(a[r], a[i], j);
		r++;
	}
	return r;
}

struct LightSwitches
{
	long long countPossibleConfigurations(vs s)
	{
		int n = s.size(), m = s[0].size();
		vector<bitset<N>> mat(n);
		rep(i, n) rep(j, m) mat[i][j] = s[i][j] == 'Y';
		return 1ll << rref(mat);
	}
};
