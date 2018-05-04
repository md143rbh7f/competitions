#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define fst first
#define snd second

constexpr int N = 100005;
constexpr ll INF = 1ll << 60;
pii pts[N];
ll val[2 * N], cost[N], nxt_cost[N];

namespace window {
int cnt[N], med, tot;
ll dist;

void inc(int i) {
	for (; i < N; i += i&(-i)) cnt[i]++;
	tot++;
}

void dec(int i) {
	for (; i < N; i += i&(-i)) cnt[i]--;
	tot--;
}

int find(int s) {
	int i, del = 1;
	for (i = N / 2; i; i /= 2) del *= 2;
	for (i = 0; del; del /= 2) if (i + del < N && cnt[i + del] < s)
		i += del, s -= cnt[i];
	return i;
}

void balance() {
	if (tot == 0) return;
	int old = med;
	med = val[find((tot + 1) / 2) + 1];
	if (med > old) dist -= 2ll * (med - old);
}

void _add(int i) {
	inc(i);
	if (tot == 1) med = val[i];
	dist += abs(val[i] - med);
}

void _remove(int i) {
	dec(i);
	dist -= abs(val[i] - med);
}

void add(int i) {
	_add(pts[i].fst);
	_add(pts[i].snd);
	balance();
}

void remove(int i) {
	_remove(pts[i].fst);
	_remove(pts[i].snd);
	balance();
}
}

struct state { int l, r, b; };
state q[N], nxt_q[N];

void work(int n) {
	q[0] = {1, n + 1, n};
	int qn = 1;
	while (qn) {
		int nxt_qn = 0, wl = 0, wr = 0;
		range (s, q, q + qn) {
			int k = (s->l + s->r) / 2, c = -1;
			nxt_cost[k] = INF;
			while (wr < k) window::add(wr++);
			while (true) {
				if (cost[wl] + window::dist < nxt_cost[k]) {
					nxt_cost[k] = cost[wl] + window::dist;
					c = wl;
				}
				if (wl + 1 < k && wl + 1 < s->b) window::remove(wl++);
				else break;
			}
			if (s->l < k) nxt_q[nxt_qn++] = {s->l, k, c + 1};
			if (k + 1 < s->r) nxt_q[nxt_qn++] = {k + 1, s->r, s->b};
		}
		while (wl < wr) window::remove(wl++);
		qn = nxt_qn;
		swap(q, nxt_q);
	}
	swap(cost, nxt_cost);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	rep (i, n) scanf("%d%d", &pts[i].fst, &pts[i].snd);
	sort(pts, pts + n, [](const pii & a, const pii & b) {
		return a.fst + a.snd < b.fst + b.snd;
	});

	map<ll, map<int, int>> id;
	rep (i, n) id[pts[i].fst][2 * i] = id[pts[i].snd][2 * i + 1] = 0;

	int cnt = 1;
	for (auto & p : id) for (auto & q : p.snd) {
		val[cnt] = p.fst;
		q.snd = cnt;
		cnt++;
	}
	rep (i, n) {
		pts[i].fst = id[pts[i].fst][2 * i];
		pts[i].snd = id[pts[i].snd][2 * i + 1];
	}

	rep (i, n) cost[i + 1] = INF;
	rep (_, k) work(n);
	printf("%lld\n", cost[n]);

	return 0;
}
