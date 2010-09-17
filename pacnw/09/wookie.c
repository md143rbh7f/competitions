#include <stdio.h>

#define rep(i,n) for(i=0;i<n;i++)

char buf[20], g[5][5];
int i,j,x,y,z,a,b,c,d,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1},ok[5][5];

int main()
{
	while(1)
	{
		scanf("%s",buf);
		if(buf[0]=='F') break;
		g[0][0]=buf[0];
		rep(i,5) rep(j,5) if(i||j) scanf("%s",buf), g[i][j]=buf[0];
		rep(i,5) rep(j,5) ok[i][j]=1;
		rep(i,5) rep(j,5) rep(d,8)
		{
			x=i+3*dx[d],y=j+3*dy[d],a=b=c=0;
			if(x<0||x>4||y<0||y>4) continue;
			for(z=0,x=i,y=j;z<4;z++,x+=dx[d],y+=dy[d])
			switch(g[x][y])
			{
				case 'O': a++; break;
				case 'X': b++; break;
				case '*': c++; break;
			}
			if((a==3||b==3)&&c==1) for(z=0,x=i,y=j;z<4;z++,x+=dx[d],y+=dy[d]) ok[x][y]=0;
		}
		rep(i,5) rep(j,5) if(g[i][j]=='*'&&ok[i][j]) printf("%d\n",i*5+j+1);
	}
	return 0;
}
