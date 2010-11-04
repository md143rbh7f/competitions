#include <stdio.h>

int n,a[500],l[500],i,j,c;

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		for(i=0;i<n;i++) scanf("%d",&a[i]), l[i]=-1;
		for(i=0;i<n;i++)
		{
			c=0;
			for(j=0;j<n;j++)
			{
				if(c==a[i]) break;
				if(l[j]==-1||l[j]>i) c++;
			}
			for(;l[j]!=-1;j++);
			l[j]=i;
		}
		for(i=0;i<n;i++) printf("%d%c",l[i]+1,i==n-1?'\n':',');
	}
	return 0;
}
