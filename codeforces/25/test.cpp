#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

constexpr int N = 100005;

string s[3];
int f[3 * N];

template <typename T, typename U>
void kmp(T s, T t, U f) {
	int n = t - s;
	f[0] = f[1] = 0;
	range (i, 1, n) {
		int &j = f[i + 1] = f[i];
		while (j > 0 && s[i] != s[j]) j = f[j];
		if (s[i] == s[j]) j++;
	}
}

template <typename T, typename U, typename V>
int find_match(T s, T t, U u, U v, V f) {
	int n = t - s, m = v - u, j = 0;
	rep (i, n) {
		while (j > 0 && s[i] != u[j]) j = f[j];
		if (s[i] == u[j]) j++;
		if (j == m) return i - m;
	}
	return -1;
}

string join(string x, string y) {
	string z = y + "#" + x;
	kmp(all(z), f);
	return x + y.substr(f[z.size()]);
}

int main() {
	rep (i, 3) cin >> s[i];
	rep (i, 3) rep (j, 3) if (i != j) {
		kmp(all(s[j]), f);
		if (find_match(all(s[i]), all(s[j]), f) != -1) s[j] = "";
	}
	int ans = s[0].size() + s[1].size() + s[2].size();
	rep (i, 3) rep (j, 3) if (i != j) {
		ans = min(ans, (int) join(join(s[i], s[j]), s[3 ^ i ^ j]).size());
	}
	cout << ans << endl;
	return 0;
}
