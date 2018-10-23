#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define fst first
#define snd second

constexpr int N = 200005;

pii ivls[N];

int main() {
	int n, x, w, ans = 0, last = -1234567890;
	scanf("%d", &n);
	rep (i, n) {
		scanf("%d%d", &x, &w);
		ivls[i] = {x + w, x - w};
	}
	sort(ivls, ivls + n);
	range (ivl, ivls, ivls + n) if (ivl->snd >= last) {
		ans++;
		last = ivl->fst;
	}
	printf("%d\n", ans);
	return 0;
}
