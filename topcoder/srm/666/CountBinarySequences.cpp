#include <algorithm>
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

#define MOD 1000000007
#define P 55

vector<vll> id(int n)
{
	vector<vll> a(n, vll(n));
	rep(i, n) a[i][i] = 1;
	return a;
}

vector<vll> operator*(vector<vll> a, vector<vll> b)
{
	int n = a.size(), p = b.size(), m = b[0].size();
	vector<vll> c(n, vll(m));
	rep(i, n) rep(j, m) rep(k, p)
		c[i][j] = M(c[i][j] + M(a[i][k] * b[k][j]));
	return c;
}

vector<vll> operator^(vector<vll> a, ll b)
{
	if(!b) return id(a.size());
	vector<vll> next = (a * a)^(b / 2);
	return b % 2 ? next * a : next;
}

int n, m, k, p;
vi g[P], l, r;
pii rs[P];
vector<vll> H, mat[P];

bool contains(pii & a, pii & b)
{
	return a.fst <= b.fst && b.snd <= a.snd;
}

void compute_graph()
{
	rep(i, p) rs[i] = {l[i] - 1, r[i]};
	sort(rs, rs + p);
	rs[p] = {0, n};

	vi par(p, p);
	rep(i, p) rep(j, p)
	if(j != i && contains(rs[j], rs[i]) && contains(rs[par[i]], rs[j]))
		par[i] = j;

	rep(i, p) g[par[i]].push_back(i);
}

void compute_hamiltonian()
{
	H = vector<vll>(m, vll(m));
	rep(i, k)
		H[2 * i][2 * (i + 1) + 1] = H[2 * i + 1][2 * (i + 1)] = 1;
	rep(i, k + 1)
		H[2 * i][0] = H[2 * i + 1][1] = 1;
}

void compute_matrix(int v)
{
	vector<vll> & ans = mat[v] = id(m);
	int t = rs[v].fst;
	for(auto c : g[v])
	{
		compute_matrix(c);
		ans = mat[c] * (H ^ (rs[c].fst - t)) * ans;
		t = rs[c].snd;
	}
	ans = (H ^ (rs[v].snd - t)) * ans;

	if(v != p) rep(i, m) rep(j, m) if((i ^ j) & 1)
		ans[i][j] = 0;
}

struct CountBinarySequences
{
int countSequences(int _n, int _k, vi _l, vi _r)
{
	n = _n, l = _l, r = _r, p = l.size(), k = _k, m = 2 * (k + 1);
	compute_graph();
	compute_hamiltonian();
	compute_matrix(p);
	ll ans = 0;
	rep(i, m) ans = M(ans + mat[p][0][i]);
	return ans;
}
};
