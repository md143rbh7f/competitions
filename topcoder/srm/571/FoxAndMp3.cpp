#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

vector<string> ans;
int n;

void rec(long long tot, int lo, int hi)
{
	if(tot > n || ans.size() == 50) return;
	if(tot)
	{
		stringstream s;
		s << tot << ".mp3";
		ans.push_back(s.str());
	}
	range(c, lo, hi) rec(10 * tot + c, 0, 10);
}

struct FoxAndMp3
{
	vector<string> playList(int _n)
	{
		n = _n;
		rec(0, 1, 10);
		return ans;
	}
};
