#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <set>
#include <utility>

using namespace std;

typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

#define N 55

int n, m, code[N];
bool g[N][N];

struct Cmp { bool operator() (int a, int b) { return code[a] < code[b]; } };

void go(list<int> & st, int j, int k)
{
	while(st.front() != j) st.pop_front();
	st.push_front(k);
}

void dfs(int i, set<int> & seen)
{
	rep(j, n) if(g[i][j] && !seen.count(j))
	{
		seen.insert(j);
		dfs(j, seen);
	}
}

pii get_next(list<int> & st, set<int> & seen, set<int, Cmp> & q)
{
	for(auto & k : q) for(auto & j : st) if(g[j][k])
	{
		list<int> st1 = st;
		go(st1, j, k);
		set<int> seen1 = seen;
		for(auto & l : st1) dfs(l, seen1);
		if(seen1.size() == n) return {j, k};
		break;
	}
	return {-1, -1};
}

void work()
{
	cin >> n >> m;
	rep(i, n) cin >> code[i];
	clr0(g);
	rep(i, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x][y] = g[y][x] = true;
	}
	int lo = -1;
	rep(i, n) if(lo == -1 || code[i] < code[lo]) lo = i;

	list<int> st {lo};
	set<int> seen {lo};
	set<int, Cmp> q;
	rep(t, n)
	{
		int i = st.front();
		seen.insert(i);
		cout << code[i];
		rep(j, n) if(g[i][j] && !seen.count(j)) q.insert(j);
		if(q.empty()) break;
		pii e = get_next(st, seen, q);
		q.erase(e.second);
		go(st, e.first, e.second);
	}
}

int main()
{
	int t;
	cin >> t;
	rep(i, t)
	{
		cout << "Case #" << i + 1 << ": ";
		work();
		cout << endl;
	}
	return 0;
}
