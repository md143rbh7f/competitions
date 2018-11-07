#include <algorithm>
#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

using vi = vector<int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

constexpr int N = 1005;

vi g[N];
bool mine[N], seen[N];

void work() {
	int n;
	scanf("%d", &n);

	rep (i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b), g[b].push_back(a);
	}

	int k;
	scanf("%d", &k);
	rep (i, k) {
		int x;
		scanf("%d", &x);
		mine[x] = true;
	}

	int m;
	scanf("%d", &m);
	vi other;
	rep (i, m) {
		int x;
		scanf("%d", &x);
		other.push_back(x);
	}

	int start;
	printf("B %d\n", other[0]); fflush(stdout);
	scanf("%d", &start);

	int closest;
	deque<int> q {start};
	seen[start] = true;
	while (!q.empty()) {
		int u = q.front();
		if (mine[u]) {
			closest = u;
			break;
		}
		q.pop_front();
		for (auto v : g[u]) if (!seen[v]) {
			q.push_back(v);
			seen[v] = true;
		}
	}

	printf("A %d\n", closest); fflush(stdout);
	int closest_other;
	scanf("%d", &closest_other);
	bool found = find(all(other), closest_other) != other.end();
	printf("C %d\n", found ? closest : -1); fflush(stdout);

	range (i, 1, n + 1) {
		g[i].clear();
		mine[i] = seen[i] = false;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}
