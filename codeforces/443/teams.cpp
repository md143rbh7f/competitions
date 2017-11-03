#include <iostream>
#include <numeric>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 100005;

int xs[N], cs[N];

ll work() {
	int n, k, m;
	cin >> n >> k >> m;

	int x, s = 0;
	rep (_, n) {
		cin >> x;
		if (s == 0 || x != xs[s - 1]) {
			xs[s] = x;
			cs[s] = 1;
			s++;
		} else {
			cs[s - 1]++;
			if (cs[s - 1] == k) s--;
		}
	}

	int total = accumulate(cs, cs + s, 0);
	if (m == 1) return total;

	int t = 0, removed = 0;
	while (t < s && xs[t] == xs[s - t - 1]) {
		int match = cs[t] + cs[s - t - 1];
		if (match >= k) removed += k;
		if (match != k) break;
		t++;
	}

	if (t == s) return (m % 2) * total;
	if (s % 2 && s / 2 == t) {
		ll middle = ((ll) m * cs[t]) % k;
		return middle ? total - cs[t] + middle : 0;
	}
	return (ll) m * total - (ll) (m - 1) * removed;
}

int main() {
	cout << work() << endl;
	return 0;
}
