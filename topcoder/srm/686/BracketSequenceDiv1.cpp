#include <cstring>
#include <string>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr1(i) CLR(i,-1)

#define N 45

string s;
int n;
ll mem[N][N];

ll work(int i, int j) {
	if(j - i < 2) return 1;
	ll & ans = mem[i][j];
	if(ans != -1) return ans;
	ans = 1;
	range(k, i, j) range(l, k + 1, j)
	if((s[k] == '(' && s[l] == ')') || (s[k] == '[' && s[l] == ']'))
		ans += work(k + 1, l) * work(l + 1, j);
	return ans;
}

struct BracketSequenceDiv1 {
long long count(string _s) {
	s = _s;
	n = s.size();
	clr1(mem);
	return work(0, n) - 1;
}
};
