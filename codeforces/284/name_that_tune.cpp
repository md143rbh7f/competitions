#include <cmath>
#include <cstdio>
#include <utility>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define K 5005

double buf[2 * K], * cur = buf, * nxt = buf + K;

int main()
{
	int N, T;
	scanf("%d%d", &N, &T);

	double ans = 0;
	cur[0] = 1;
	rep(i, N)
	{
		int q, maxt;
		scanf("%d%d", &q, &maxt);
		double p = q * 0.01, endp = pow(1 - p, maxt), s = 0;
		rep(t, T + 1)
		{
			double adj = t >= maxt ? endp * cur[t - maxt] : 0;
			ans += (nxt[t] = p * s + adj);
			s = (1 - p) * s + cur[t] - adj;
		}
		swap(cur, nxt);
	}

	printf("%.9lf\n", ans);

	return 0;
}
