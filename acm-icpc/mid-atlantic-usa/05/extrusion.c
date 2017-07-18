#include <stdio.h>

int n;
double x0,y0,x1,y1,x2,y2,v,a;

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n<3) break;
		scanf("%lf%lf",&x0,&y0);
		x1=x0, y1=y0, a=0;
		while(--n)
		{
			scanf("%lf%lf",&x2,&y2);
			a+=x1*y2-x2*y1;
			x1=x2, y1=y2;
		}
		a+=x1*y0-x0*y1;
		a/=2;
		if(a<0) a*=-1;
		scanf("%lf",&v);
		printf("BAR LENGTH: %.2lf\n",v/a);
	}
	return 0;
}
