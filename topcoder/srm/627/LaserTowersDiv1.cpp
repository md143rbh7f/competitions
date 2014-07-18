#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)

#define K 55
#define M 505
#define N 1005
#define INF 123456789

vs board;
int ans, r, c, rn, rw[M], rid[K][K], cn, cw[M], cid[K][K];
bool rp[M], cp[M];

inline int val(char c) { return '1' <= c && c <= '9' ? c - '0' : 0; }

void work(int id[K][K], int & m, int w[M], bool p[M], char s, int dx, int dy)
{
	rep(i, r) rep(j, c) if(board[i][j] == s)
	{
		int u = i, v = j, prev = 0;
		bool par = false;
		for(int x = i, y = j; 0 <= x && x < r && 0 <= y && y < c; x += dx, y += dy)
		{
			int cur = val(board[x][y]);
			if(cur <= prev) continue;
			for(int z = x, w = y; z != u || w != v; z -= dx, w -= dy)
				id[z][w] = m;
			w[m] = cur - prev, p[m] = par;
			prev = cur, par = true, m++;
			u = x, v = y;
		}
		ans += prev;
	}
}

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

bool seen[N];

int dfs(int s, int t, int mf)
{
	if(s == t) return mf;
	if(seen[s]) return 0;
	seen[s] = true;
	for(auto e : g[s]) if(e->c > e->f)
	{
		int mf2 = min(mf, e->c - e->f);
		mf2 = min(mf2, dfs(e->j, t, mf2));
		if(mf2)
		{
			e->f += mf2, e->r->f -= mf2;
			return mf2;
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	for(clr0(seen); dfs(s, t, INF); clr0(seen));
	int ans = 0;
	for(auto e : g[s]) ans += e->f;
	return ans;
}

struct LaserTowersDiv1
{
int countMaxEnemies(vs _board)
{
	board = _board, r = board.size(), c = board[0].size();
	clr1(rid), clr1(cid);
	work(rid, rn, rw, rp, '<', 0, -1);
	work(rid, rn, rw, rp, '>', 0, 1);
	work(cid, cn, cw, cp, 'A', -1, 0);
	work(cid, cn, cw, cp, 'V', 1, 0);

	n = rn + cn + 2;
	rep(i, rn)
	{
		add_edge(n - 2, i, rw[i]);
		if(rp[i]) add_edge(i, i - 1, INF);
	}
	rep(j, cn)
	{
		add_edge(rn + j, n - 1, cw[j]);
		if(cp[j]) add_edge(rn + j - 1, rn + j, INF);
	}
	rep(i, r) rep(j, c) if(rid[i][j] >= 0 && cid[i][j] >= 0)
		add_edge(rid[i][j], rn + cid[i][j], INF);

	return ans - max_flow(n - 2, n - 1);
}
};
