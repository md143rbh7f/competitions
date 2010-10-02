#include <stdio.h>

int t,n,a[47],w,s,i,r,c,d;
char win[][10] = { "John\n", "Brother\n" };

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		w=0;
		while(1)
		{
			s=0;
			for(i=0;i<n;i++) s+=a[i];
			if(!s) break;
			s=0;
			for(i=0;i<n;i++) s^=a[i];
			if(s)
			{
				for(i=0;i<n;i++) if(a[i]>=(s^a[i]))
				{
					r=i,d=a[i]-(s^a[i]);
					break;
				}
				c=(a[r]-d)>1;
				for(i=0;i<n;i++) if(i!=r&&a[i]>1) c++;
				if(c==0)
				{
					c=0;
					for(i=0;i<n;i++) if(a[i]==1) c++;
					if(c%2) d=a[r];
					else d=a[r]-1;
				}
			}
			else for(i=0;i<n;i++) if(a[i])
			{
				r=i,d=a[i];
				break;
			}
			a[r]-=d,w=1-w;
		}
		printf("%s",win[w]);
	}
	return 0;
}
