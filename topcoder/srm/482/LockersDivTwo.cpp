#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int l[2000000];

struct LockersDivTwo
{
	int lastOpened( int n )
	{
		int last = -1, l0 = n, l1 = 0, cnt = 0;
		rep(i,n) l[i] = i;
		for(int d=2;l0;d++)
		{
			rep(i,l0)
			{
				if(!cnt) last=l[i];
				else l[l1++] = l[i];
				cnt = (cnt+1)%d;
			}
			l0 = l1;
			l1 = cnt = 0;
		}
		return last+1;
	}
};
