#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)

#define N 6000

#define INF 1234567

struct Edge
{
	int j, c, f;
	Edge * r;
};

vector<Edge*> g[N];
int n;

void add_edge(int i, int j, int c = 1)
{
	Edge* e = new Edge{j, c, 0, 0}, *f = new Edge{i, 0, 0, 0};
	e->r = f, f->r = e;
	g[i].push_back(e), g[j].push_back(f);
}

Edge* pre[N];

int bfs(int s, int t)
{
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int i = q.front();
		q.pop();
		for(auto e : g[i]) if(e->c > e->f && e->j != s && !pre[e->j])
			pre[e->j] = e, q.push(e->j);
	}
	if(!pre[t]) return 0;
	int f = INF;
	for(Edge* e = pre[t]; e; e = pre[e->r->j])
		f = min(f, e->c - e->f);
	for(Edge* e = pre[t]; e; e = pre[e->r->j])
		e->f += f, e->r->f -= f;
	return f;
}

int max_flow(int s, int t)
{
	for(clr0(pre); bfs(s, t); clr0(pre));
	int ans = 0;
	for(auto e : g[s]) ans += e->f;
	return ans;
}

int work()
{
	int m;
	string line, word;
	cin >> m;
	getline(cin, line);

	unordered_map<string, int> id;
	vector<unordered_set<int>> ss(m);
	rep(i, m)
	{
		getline(cin, line);
		istringstream iss(line);
		while(iss >> word)
		{
			if(!id.count(word)) id[word] = id.size() - 1;
			ss[i].insert(id[word]);
		}
	}

	int p = id.size();
	n = m + 2 * p + 2;

	add_edge(n - 2, 0, INF);
	add_edge(1, n - 1, INF);

	rep(i, m) for(auto j : ss[i])
	{
		add_edge(i, m + j, INF);
		add_edge(m + p + j, i, INF);
	}

	rep(j, p) add_edge(m + j, m + p + j);

	return max_flow(n - 2, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	rep(i, t)
	{
		cout << "Case #" << i + 1 << ": " << work() << endl;
		rep(j, N) g[j].clear();
	}
	return 0;
}
