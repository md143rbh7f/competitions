#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

string c;
int t;

int rec()
{
	char d = c[t++];
	return d == 'A' ? rec() + rec() : d == 'B' ? max(rec(), rec()) : 1;
}

struct CircuitsConstruction
{
int maximizeResistance(string _c, vi x)
{
	c = _c;
	sort(all(x), greater<int>());
	int s = rec(), ans = 0;
	rep(i, s) ans += x[i];
	return ans;
}
};
