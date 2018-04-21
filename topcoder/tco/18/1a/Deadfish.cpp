#include <algorithm>
#include <queue>
#include <string>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

constexpr int N = 200005;

int dist[N];

int* gen(int i, int *res) {
	if (i < N) *(res++) = i + 1;
	if (i) *(res++) = i - 1;
	if ((ll) i * i <= N) *(res++) = i * i;
	string s = to_string(i);
	sort(all(s));
	reverse(all(s));
	int j = stoi(s);
	if (j <= N) *(res++) = j;
	return res;
}

struct Deadfish {
int shortestCode(int n) {
	deque<int> q {0};
	while (!q.empty()) {
		int i = q.front();
		q.pop_front();
		int j0[5], *j1 = gen(i, j0);
		range (j, j0, j1) {
			if (j == 0 || dist[*j]) continue;
			dist[*j] = dist[i] + 1;
			q.push_back(*j);
		}
	}
	return dist[n];
}
};
