#include <cmath>
#include <iostream>
#include <iterator>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define fst first
#define snd second

double len = -1;
vector<pii> ans;
int n, m;

void add(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3)
{
	vector<pii> test {{x0, y0}, {x1, y1}, {x2, y2}, {x3, y3}};
	for(auto p : test) if(p.fst < 0 || p.fst > n || p.snd < 0 || p.snd > m) return;
	double l = hypot(x0 - x1, y0 - y1) + hypot(x1 - x2, y1 - y2) + hypot(x2 - x3, y2 - y3);
	if(set<pii>(all(test)).size() == 4 && l > len) ans = test, len = l;
}

int main()
{
	cin >> n >> m;
	add(0, 1, n, m, 0, 0, n, m - 1);
	add(1, 0, n, m, 0, 0, n - 1, m);
	add(0, 0, n, m, n, 0, 0, m);
	add(0, 0, n, m, 0, m, n, 0);
	for(auto p : ans) cout << p.fst << " " << p.snd << endl;
	return 0;
}
