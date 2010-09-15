#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int p[19], have;

void solve_dave( int source, int target, int spare, int n )
{
	if(!n||!have) return;
	solve_dave( source, spare, target, n-1 );
	if(!have) return;
	p[n-1] = target;
	have--;
	if(!have) return;
	solve_dave( spare, target, source, n-1 );
}

struct HanoiGoodAndBad
{
	int moves( int n, int dave )
	{
		int source = 0, target = 2, spare = 1;
		have = dave;
		solve_dave( source, target, spare, n );
		int pow = 1, ans = 0;
		for( int i = n-1; i >= 0; i-- ) if( p[i]==1 ) rep(j,i) p[j] = 2-p[j];
		rep(i,n) ans += pow*p[i], pow *= 3;
		return ans;
	}
};
