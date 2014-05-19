#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

struct NewArenaPassword
{
	int minChange(string s, int k)
	{
		int ans = 0, n = s.size();
		rep(i, min(k, n - k))
		{
			map<char,int> c;
			for(int j = i; j < n; j += n - k) c[s[j]]++;
			int top = 0, tot = 0;
			for(auto & p : c) tot += p.second, top = max(top, p.second);
			ans += tot - top;
		}
		return ans;
	}
};
