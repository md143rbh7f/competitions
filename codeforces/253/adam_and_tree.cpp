#include <algorithm>
#include <cstdio>

using namespace std;

#define N 1000005

int p[N], a[N], b[N], f[N];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		p[i]--;
		for(int x = i; x; x = p[x])
		{
			int y = max(a[x], b[x] + 1);
			if(y <= f[x]) break;
			f[x] = y;
			if(y > a[p[x]]) a[p[x]] = y;
			else if(y > b[p[x]]) b[p[x]] = y;
		}
		printf("%d ", max(a[0], b[0]));
	}
	return 0;
}
