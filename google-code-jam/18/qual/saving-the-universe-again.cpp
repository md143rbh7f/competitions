#include <cstdio>
#include <functional>
#include <set>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int SZ = 35;

char s[SZ];

int work() {
	int d, tot = 0, cur = 1, ans = 0;
	scanf("%d%s", &d, s);
	multiset<int, greater<int>> nums;
	for (auto c : s) {
		if (c == 'C') cur *= 2;
		else if (c == 'S') tot += cur, nums.insert(cur);
		else break;
	}
	for (; tot > d; ans++) {
		auto it = nums.begin();
		cur = *it;
		if (cur == 1) return -1;
		nums.erase(it);
		nums.insert(cur / 2);
		tot -= cur / 2;
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) {
		printf("Case #%d: ", i + 1);
		int ans = work();
		if (ans >= 0) printf("%d\n", ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
