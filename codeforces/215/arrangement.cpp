#include <algorithm>
#include <iostream>

using namespace std;

int w[100005], n, m, tmp, i;
long long ans;

int main()
{
	cin >> n >> m;
	for(i = 0; i < m; i++) cin >> tmp >> w[i];
	sort(w, w + m);
	for(i = 1; i / 2 * i + i % 2 <= n && i <= m; i++) ans += w[m-i];
	cout << ans << endl;
	return 0;
}
