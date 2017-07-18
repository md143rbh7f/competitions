#include <algorithm>
#include <iostream>

using namespace std;

#define iter(i,a,b,c) for(__typeof__(a) i=(a);i c(b);i++)
#define range(i,a,b) iter(i,a,b,<)
#define rep(i,n) range(i,0,n)

#define M 1000005
#define MAX (1<<30)

int p[M], n, k, m, ans;

int main()
{
	cin >> n >> k;
	m = 2 * n * k;
	rep(i,m) cin >> p[i];
	sort( p, p + m );
	k = 2 * k - 1, m -= k;
	rep(i,m) p[i] = p[i+1] - p[i];

	int ans = MAX - 1;
	for( int d = MAX / 2; d; d /= 2 )
	{
		int test = ans - d, cnt = 0, have = 0;
		rep(i,m)
		{
			if( have == 0 && p[i] > test )
			{
				cnt = -1;
				break;
			}
			if( p[i] <= test ) cnt++, i++, have += k;
			have--;
		}
		if( cnt >= n ) ans = test;
	}
	cout << ans << endl;

	return 0;
}
