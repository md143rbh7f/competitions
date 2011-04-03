#define L 11

long long ans, p[L+1];
int n, m, k, s[L];

void rec( int x, int y )
{
	if(x==n)
	{
		int cnt = 0;
		for( int i = 0; i+m <= n; i++ )
		{
			bool ok = true;
			for( int j = 0; j < m; j++ ) if(s[i+j]!=s[i+m-j-1]) ok = false;
			if(ok) cnt++;
		}
		if( cnt >= k ) ans += p[y];
	}
	else for( s[x] = 0; s[x] <= y; s[x]++ ) rec( x+1, s[x] == y ? y+1 : y );
}

struct PalindromfulString
{
	long long count( int N, int M, int K )
	{
		n = N, m = M, k = K;
		p[0] = 1;
		for( int i = 1; i <= L; i++ ) p[i] = p[i-1]*(26-i+1);
		rec(0,0);
		return ans;
	}
};
