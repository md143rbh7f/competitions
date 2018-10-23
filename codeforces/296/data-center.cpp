#include <cstdio>
#include <vector>

using namespace std;

using vi = vector<int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 100005, M = 250005;

vi g[N];
int x[M], tour_prev;
bool used[M], tour_dir;

void add(int e, int u, int v) {
	x[e] = u ^ v;
	g[u].push_back(e);
	g[v].push_back(e);
}

void visit_node(int u) {
	if (tour_prev) {
		if (tour_dir) printf("%d %d\n", tour_prev, u);
		else printf("%d %d\n", u, tour_prev);
		tour_dir = !tour_dir;
	}
	tour_prev = u;
}

void tour(int u) {
	while (!g[u].empty()) {
		int e = g[u].back();
		g[u].pop_back();
		if (used[e]) continue;
		used[e] = true;
		tour(u ^ x[e]);
	}
	visit_node(u);
}

int main() {
	int n, m, u, v;
	scanf("%d%d", &n, &m);
	range (e, 1, m + 1) {
		scanf("%d%d", &u, &v);
		add(e, u, v);
	}

	v = 0;
	range (u, 1, n + 1) if (g[u].size() % 2) {
		if (v) {
			add(++m, u, v);
			v = 0;
		} else v = u;
	}
	if (m % 2) add(++m, 1, 1);

	printf("%d\n", m);
	tour(1);

	return 0;
}
