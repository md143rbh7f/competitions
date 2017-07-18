#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRIALS 1000000

int n,i,t,tot,ok;
double X,Y,R,x[25],y[25],r[25],tx,ty;

double rand2()
{
	return 2*R*rand()/RAND_MAX-R;
}

double d2( double xa, double ya, double xb, double yb )
{
	return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		scanf("%lf%lf%lf",&X,&Y,&R);
		for(i=1;i<n;i++) scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
		ok=tot=0;
		for(t=0;t<MAX_TRIALS;t++)
		{
			tx=rand2()+X,ty=rand2()+Y;
			if(d2(tx,ty,X,Y)<=R)
			{
				for(i=1;i<n;i++) if(d2(tx,ty,x[i],y[i])<=r[i])
				{
					ok++;
					break;
				}
				tot++;
			}
		}
		printf("%.2lf\n",1.0*ok/tot);
	}
	return 0;
}
