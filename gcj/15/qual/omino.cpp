#include <cstdio>
#include <utility>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

bool can_fill(int x, int r, int c)
{
	if(r < c) swap(r, c);
	if(x > 2 * c || (r * c) % x) return false;
	if(x <3) return true;
	if(x == 3) return c > 1;
	if(x == 4) return c > 2 && r > 3;
	if(x == 5) return c > 2 && (c > 3 || r > 5);
	if(x == 6) return c > 3;
	return false;
}

int main()
{
	int t;
	scanf("%d", &t);
	rep(i, t)
	{
		int x, r, c;
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: %s\n", i + 1, can_fill(x, r, c) ? "GABRIEL" : "RICHARD");
	}
	return 0;
}
