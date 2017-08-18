#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 200005

int n, m, cnt, s[N], t[N], p[N];

bool update(int i, int v)
{
	if(!i) v = 0;
	bool old = t[i] > 0;
	return (cnt += ((t[i] += v) > 0) - old) > 0;
}

int main()
{
	scanf("%d%d", &n, &m);
	range(i, 1, n) scanf("%d", p + i);
	rep(i, n) scanf("%d", s + i);
	range(i, 1, n) update(i, s[i] - s[p[i] - 1]);
	rep(i, m)
	{
		int e, v;
		scanf("%d%d", &e, &v);
		printf(update(e - 1, v) ? "BAD\n" : "GOOD\n");
	}
	return 0;
}
