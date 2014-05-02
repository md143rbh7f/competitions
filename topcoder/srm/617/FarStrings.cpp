#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 30

int n, a[N][N];
string s, t;

int dist()
{
	rep(i, n + 1) a[0][i] = a[i][0] = i;
	rep(i, n) rep(j, n) a[i + 1][j + 1] = min(
		(t[j] < 'a' ? t[j] : s[i] != t[j]) + a[i][j],
		1 + min(a[i][j + 1], a[i + 1][j])
	);
	return a[n][n];
}

string work(int m)
{
	t = string(n, ' ');
	rep(i, n) for(t[i] = 'a'; t[i] <= 'z'; t[i]++)
	{
		range(j, i + 1, n) t[j] = 0;
		if(dist() > m) continue;
		range(j, i + 1, n) t[j] = 1;
		if(dist() < m) continue;
		break;
	}
	return t;
}

struct FarStrings
{
	vector<string> find(string _s)
	{
		s = _s, n = s.size();
		vector<string> ans;
		rep(i, n) ans.push_back(work(i + 1));
		return ans;
	}
};
