#include "stdio.h"

#define L 3
#define REP(i,a,b) for(i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

char s[105];
int T, cnt[L], tot, n, i, j, c;

int main()
{
	rep(c,L) tot ^= c;

	for( scanf( "%d", &T ); T; T-- )
	{
		scanf( "%s", s );

		rep(c,L) cnt[c] = 0;
		for( n = 0; s[n]; n++ )
		{
			s[n] -= 'a';
			cnt[s[n]]++;
		}

		while( !cnt[0] + !cnt[1] + !cnt[2] < 2 )
		{
			int maxc = 0;
			rep(c,L) if( cnt[c] > cnt[maxc] ) maxc = c;
			rep(i,n-1) if( s[i] != s[i+1] && ( s[i] == maxc || s[i+1] == maxc ) )
			{
				cnt[s[i]]--, cnt[s[i+1]]--;
				s[i] = tot ^ s[i] ^ s[i+1];
				cnt[s[i]]++;
				n--;
				REP(j,i+1,n) s[j] = s[j+1];
				break;
			}
		}

		printf( "%d\n", n );
	}
	return 0;
}
