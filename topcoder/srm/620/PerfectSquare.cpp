#include <iostream>

#include <algorithm>
#include <bitset>
#include <map>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define MOD 1000000007
#define M 401

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

struct PerfectSquare
{
	int ways(vi x)
	{
		int m = x.size(), n = sqrt(m);

		vector<bitset<M>> a;
		rep(i, n)
		{
			bitset<M> r, c;
			rep(j, n) r[i * n + j] = c[i + j * n] = true;
			r[m] = c[m] = true;
			a.push_back(r), a.push_back(c);
		}

		map<int, bitset<M>> ps;
		rep(i, m)
		{
			int z = x[i];
			for(ll f = 2; f * f <= z; f++) if(!(z % f))
			{
				bool ok = false;
				while(!(z % f)) z /= f, ok ^= 1;
				if(ok) ps[f][i] = true;
			}
			if(z > 1) ps[z][i] = true;
		}
		for(auto & p : ps) a.push_back(p.second);

		int d = m - rref(a, m), ans = 1;
		for(auto & r : a) if(r[m] && r.count() == 1) return 0;
		while(d--) ans = (2 * ans) % MOD;
		return ans;
	}
};
