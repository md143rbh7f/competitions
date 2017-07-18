#include <iostream>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

string in;
int n,t,v[6][8],d[8],tot[6],ptr,a,b,bd,best[8];

int main()
{
	while(1)
	{
		cin >> in;
		if(cin.fail()) break;
		cin >> t >> n;
		rep(i,n) rep(j,t) cin >> v[i][j];
		bd=111111;
		while(1)
		{
			rep(i,n) tot[i]=0;
			rep(i,t) tot[d[i]]+=v[d[i]][i];
			a=111111, b=0;
			rep(i,n) if(tot[i]<a) a=tot[i];
			rep(i,n) if(tot[i]>b) b=tot[i];
			if(b-a<bd)
			{
				bd=b-a;
				rep(i,t) best[i]=d[i];
			}
			ptr=t-1;
			while(ptr>=0&&d[ptr]==n-1) ptr--;
			if(ptr<0) break;
			d[ptr]++;
			REP(i,ptr+1,t) d[i]=0;
		}
		rep(i,n)
		{
			tot[i]=0;
			rep(j,t) if(best[j]==i) tot[i]+=v[i][j], cout << j+1 << " ";
			cout << tot[i] << endl;
		}
		cout << endl;
		rep(i,t) d[i]=0;
		cin >> in;
	}
	return 0;
}
