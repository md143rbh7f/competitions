#include <stdio.h>

#define MAX 10000

char s[MAX];
int l, dp[MAX];

int main()
{
	while(1)
	{
		scanf( "%s", s );
		if( s[0]=='0' ) break;
		for( l = 0; s[l]; l++ ) s[l] -= '0';
		dp[l] = 1;
		dp[l-1] = s[l-1] ? 1 : 0;
		for( l = l-2; l >= 0; l-- ) dp[l] = s[l] ? ( dp[l+1] + ( s[l] * 10 + s[l+1] <= 26 ? dp[l+2] : 0 ) ) : 0;
		printf( "%d\n", dp[0] );
	}
	return 0;
}
