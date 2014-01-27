#include <iostream>
#include <string>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 1<<21

struct tup { int a, b, c; };

int n, m;
string s;
tup tr[N];

#define v 2*u, i, (i + j) / 2
#define w 2*u + 1, (i + j) / 2, j

inline tup merge(tup l, tup r)
{
	int match = min(l.b, r.a);
	return { l.a + r.a - match, l.b + r.b - match, l.c + r.c + 2 * match };
}

tup init(int u = 1, int i = 0, int j = n)
{
	if(i + 1 == j) return tr[u] = s[i] == ')' ? tup{1, 0, 0} : tup{0, 1, 0};
	return tr[u] = merge(init(v), init(w));
}

tup query(int a, int b, int u = 1, int i = 0, int j = n)
{
	if(a <= i && j <= b) return tr[u];
	if(b <= i || j <= a) return {0, 0, 0};
	return merge(query(a, b, v), query(a, b, w));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> s;
	n = s.size();
	init();
	cin >> m;
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		cout << query(a - 1, b).c << endl;
	}
	return 0;
}
