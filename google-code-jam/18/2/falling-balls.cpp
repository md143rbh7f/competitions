#include <iostream>
#include <string>
#include <vector>

using namespace std;

using vi = vector<int>;
using vs = vector<string>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 105;

int cnt[N];

void work() {
	int n;
	cin >> n;
	rep (i, n) cin >> cnt[i];

	if (cnt[0] == 0 || cnt[n - 1] == 0) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	int l = 0;
	vi ls, rs, xs;
	rep (i, n) if (cnt[i]) {
		xs.push_back(i);
		ls.push_back(l);
		int r = l + cnt[i];
		rs.push_back(r);
		l = r;
	}

	int m = xs.size();
	vs ans;
	while (true) {
		bool changed = false;
		string s(n, '.');
		rep (j, m) {
			if (ls[j] < xs[j]) {
				changed = true;
				s[ls[j]++] = '\\';
			} else if (ls[j] > xs[j]) {
				changed = true;
				ls[j]--;
			}

			if (rs[j] < xs[j] + 1) {
				changed = true;
				rs[j]++;
			} else if (rs[j] > xs[j] + 1) {
				changed = true;
				s[--rs[j]] = '/';
			}
		}
		ans.push_back(s);

		if (!changed) break;
	}

	cout << ans.size() << endl;
	for (auto s : ans) cout << s << endl;
}

int main() {
	int t;
	cin >> t;
	rep (i, t) {
		cout << "Case #" << i + 1 << ": ";
		work();
	}
	return 0;
}
