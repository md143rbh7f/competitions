#include <iostream>

using namespace std;

int n, m, i, j, a, b, ans, korobki[11];

int main()
{
	cin >> n >> m;
	for( i = 0; i < m; i++ )
	{
		cin >> a >> b;
		korobki[b] += a;
	}
	for( i = 10; i>=0; i-- )
	{
		j = min( korobki[i], n );
		ans += i*j;
		n -= j;
	}
	cout << ans;
	return 0;
}
