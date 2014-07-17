#include <algorithm>
#include <cstdio>

using namespace std;

#define N 100005

int ans = 1, n, a[N], b[N], c[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for(int i = 1; i <= n; i++)
		b[i] = 1 + (1 < i && a[i - 1] < a[i] ? b[i - 1] : 0);
	for(int i = n; i >= 1; i--)
		c[i] = 1 + (i < n && a[i] < a[i + 1] ? c[i + 1] : 0);
	for(int i = 1; i <= n; i++)
	{
		if(1 < i) ans = max(ans, 1 + b[i - 1]);
		if(i < n) ans = max(ans, 1 + c[i + 1]);
		if(1 < i && i < n && a[i + 1] - a[i - 1] > 1)
			ans = max(ans, b[i - 1] + c[i + 1] + 1);
	}
	printf("%d", ans);
	return 0;
}
