#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 55

bool used[N], d[N];

struct CandidatesSelection
{
	string possible(vs s, vi p)
	{
		int n = s.size(), m = s[0].size();
		d[p[0]] = true;
		rep(t, m) rep(j, m) if(!used[j])
		{
			bool ok = true;
			rep(i, n) ok &= d[p[i]] || s[p[i]][j] >= s[p[i-1]][j];
			if(!ok) continue;
			used[j] = true;
			rep(i, n) if(!d[p[i]]) d[p[i]] |= s[p[i]][j] > s[p[i-1]][j];
		}
		rep(i, n) if(!d[p[i]] && p[i] < p[i-1]) return "Impossible";
		return "Possible";
	}
};
