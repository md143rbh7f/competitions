#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 8

int n, p[MAX];
double V, X[MAX], Y[MAX], v[MAX], q[MAX], x[MAX], y[MAX], INF = 1e6;

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		scanf("%lf",&V);
		rep(i,n) p[i] = i, scanf("%lf%lf%lf%lf",&X[i],&Y[i],&v[i],&q[i]);
		double ans = INF;
		do
		{
			rep(i,n) x[i] = X[i], y[i] = Y[i];
			double cx = 0, cy = 0, maxt = 0, T = 0;
			rep(I,n)
			{
				int i = p[I];
				double dx = cx-x[i], dy = cy-y[i], a = (v[i]+V)*(v[i]-V), b = -2*v[i]*(cos(q[i])*dx+sin(q[i])*dy), c = dx*dx+dy*dy, t0 = (-b+sqrt(b*b-4*a*c))/2/a, t1 = (-b-sqrt(b*b-4*a*c))/2/a, t = min( t0<0?INF:t0, t1<0?INF:t1 );
				rep(j,n) x[j] += v[j]*cos(q[j])*t, y[j] += v[j]*sin(q[j])*t;
				cx = x[i], cy = y[i], T += t;
				maxt = max(maxt,T+sqrt(x[i]*x[i]+y[i]*y[i])/v[i]);
			}
			ans = min(ans,maxt);
		}
		while(next_permutation(p,p+n));
		printf("%0.0f\n",ans);
	}
	return 0;
}
