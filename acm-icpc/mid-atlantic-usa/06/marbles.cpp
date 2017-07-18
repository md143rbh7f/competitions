#include <list>
#include <cstdio>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int a[3],ta[3],ca[3],av;
list<int> qa,qb,qc;
int prev[61][61][61][3];

void QB() { qa.push_back(ca[0]), qb.push_back(ca[1]), qc.push_back(ca[2]); }
void QF() { qa.push_front(ca[0]), qb.push_front(ca[1]), qc.push_front(ca[2]); }
void PF() { ta[0]=qa.front(), ta[1]=qb.front(), ta[2]=qc.front(), qa.pop_front(), qb.pop_front(), qc.pop_front(); }

int main()
{
	while(1)
	{
		rep(i,61) rep(j,61) rep(k,61) prev[i][j][k][0]=-1;
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		rep(i,3) ca[i]=a[i];
		QB();
		while(!qa.empty())
		{
			PF();
			rep(i,3) rep(j,3) if(ta[j]&&ta[i]>ta[j])
			{
				rep(k,3) ca[k]=ta[k];
				ca[i]-=ta[j], ca[j]+=ta[j];
				if(prev[ca[0]][ca[1]][ca[2]][0]==-1)
				{
					rep(k,3) prev[ca[0]][ca[1]][ca[2]][k]=ta[k];
					QB();
				}
			}
		}
		av=(a[0]+a[1]+a[2])/3;
		rep(i,3) ca[i]=av;
		if(prev[av][av][av][0]!=-1) while(ca[0]!=a[0]||ca[1]!=a[1]||ca[2]!=a[2])
		{
			QF();
			rep(i,3) ta[i]=prev[ca[0]][ca[1]][ca[2]][i];
			rep(i,3) ca[i]=ta[i];
		}
		rep(i,3) ca[i]=a[i];
		QF();
		while(!qa.empty())
		{
			PF();
			printf("%4d%4d%4d\n",ta[0],ta[1],ta[2]);
		}
		printf("============\n");
		if(!a[0]&&!a[1]&&!a[2]) break;
	}
	return 0;
}
