#define MAX 50

double rainbow; // all the way
double dp[MAX];

struct TheBoredomDivOne
{
	double find( int n, int m )
	{
		int tot = n+m, tot2 = (n+m)*(n+m-1);
		for( int i = 1; i <= m; i++ )
		{
			int j = tot-i;
			dp[i] = ( 1 + dp[i-1]*2*j*i/tot2 + ( i==1 ? 0 : dp[i-2]*i*(i-1)/tot2 ) ) / ( 1 - j*(j-1)*1.0/tot2 );
		}
		return dp[m];
	}
};
