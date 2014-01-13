#include <algorithm>
#include <iostream>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005
#define M 20

int c[N], cnt[M], s, x, n, m, d;
bool bad[1<<M];

int main()
{
	cin >> n >> m >> d;
	rep(i, m)
	{
		cin >> s;
		while(s--)
		{
			cin >> x;
			c[x-1] = i;
		}
	}
	int mm = (1<<m)-1, ma = 0, k = m;
	rep(i, n)
	{
		cnt[c[i]]++, ma |= 1<<c[i];
		if(i >= d && !(--cnt[c[i-d]])) ma ^= 1<<c[i-d];
		if(i >= d - 1) bad[mm^ma] = true;
	}
	for(int i = mm; i; i--)
	{
		if(!bad[i]) k = min(k, __builtin_popcount(i));
		else rep(j, m) if((i >> j) & 1) bad[i^(1<<j)] = true;
	}
	cout << k << endl;
	return 0;
}
