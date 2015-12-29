#include <bitset>
#include <cstdio>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)
#define fst first
#define snd second
#define tup make_tuple

constexpr int N = 4, D = 4, MOD = 1000000009;

int s;
unordered_map<bitset<2 * N>, int> codes;
vector<pii> edges;
bitset<N> grid[3];
vector<vll> hamiltonian[N + 1];

int dx[] = {-1, -2, -2, -1}, dy[] = {-2, -1, 1, 2};

inline bool get(int i, int j) {
	return 0 <= i && 0 <= j && j < s && grid[i][j];
}

int code(int i) {
	bitset<2 * N> state(grid[i].to_ulong() | (grid[i + 1].to_ulong() << N));
	if(!codes.count(state)) codes[state] = codes.size() - 1;
	return codes[state];
}

void rec(int i, int j) {
	if(j == s) j = 0, i++;
	if(i == 3) {
		edges.emplace_back(code(0), code(1));
		return;
	}

	grid[i][j] = false;
	rec(i, j + 1);

	rep(d, D) if(get(i + dx[d], j + dy[d])) return;
	grid[i][j] = true;
	rec(i, j + 1);
}

void compute_hamiltonian() {
	rec(0, 0);

	int n = codes.size();
	hamiltonian[s] = vector<vll>(n, vll(n));
	for(auto p : edges) hamiltonian[s][p.fst][p.snd] = 1;

	codes.clear();
	edges.clear();
}

vector<vll> id(int n) {
	vector<vll> a(n, vll(n));
	rep(i, n) a[i][i] = 1;
	return a;
}

vector<vll> operator*(vector<vll> a, vector<vll> b) {
	int n = a.size(), p = b.size(), m = b[0].size();
	vector<vll> c(n, vll(m));
	rep(i, n) rep(j, m) rep(k, p)
		c[i][j] = M(c[i][j] + M(a[i][k] * b[k][j]));
	return c;
}

vector<vll> operator^(vector<vll> a, ll b) {
	if(!b) return id(a.size());
	vector<vll> next = (a * a)^(b / 2);
	return b % 2 ? next * a : next;
}

int solve(int m, int n) {
	int k = hamiltonian[m].size();
	vector<vll> x0(k, vll(1));
	x0[0][0] = 1;

	vector<vll> x1 = (hamiltonian[m]^n) * x0;
	int ans = 0;
	rep(u, k) ans = M(ans + x1[u][0]);
	return ans;
}

int main() {
	for(s = 1; s <= N; s++)
		compute_hamiltonian();

	int t, m, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &m, &n);
		printf("%d\n", solve(m, n));
	}
	return 0;
}
