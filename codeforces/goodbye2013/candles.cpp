#include <iostream>

using namespace std;

int main()
{
	int n, m, k = 0, ans = 0;
	cin >> n >> m;
	while(n)
	{
		ans += n;
		k += n;
		n = k / m;
		k -= n * m;
	}
	cout << ans << endl;
	return 0;
}
