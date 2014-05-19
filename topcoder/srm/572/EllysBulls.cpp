#include <map>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define D 10

int t[10];

void work(map<vi, int> & ans, vs & s)
{
	int n = s.size(), m = s[0].size();
	rep(x, t[m])
	{
		vi key(n);
		rep(i, n) rep(j, m)
			key[i] += x / t[j] % 10 + '0' == s[i][j];
		auto p = ans.find(key);
		if(p == ans.end()) ans[key] = x;
		else p->second = -1;
	}
}

struct EllysBulls
{
	string getNumber(vs s, vi need)
	{
		t[0] = 1;
		range(i, 1, D) t[i] = 10 * t[i - 1];

		int n = s.size(), m = s[0].size();
		vs l, r;
		for(auto & t : s)
			l.push_back(t.substr(0, m / 2)), r.push_back(t.substr(m / 2));

		map<vi, int> sl, sr;
		work(sl, l), work(sr, r);

		int code = -2;
		for(auto & p : sl)
		{
			const vi & u = p.first;
			vi v(n);
			rep(i, n) v[i] = need[i] - u[i];
			auto q = sr.find(v);
			if(q != sr.end())
			{
				if(p.second == -1 || q->second == -1 || code != -2)
				{
					code = -1;
					break;
				}
				else code = p.second + q->second * t[m / 2];
			}
		}
		if(code == -2) return "Liar";
		if(code == -1) return "Ambiguity";
		string ans(m, '0');
		rep(j, m) ans[j] += code / t[j] % 10;
		return ans;
	}
};
