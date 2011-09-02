#define MAX 4747

int cnt[MAX+1];

struct TheLuckyGameDivTwo
{
	int find( int a, int b, int l1, int l2 )
	{
		for( int i = a; i <= b; i++ )
		{
			int ok = 1;
			for( int j = i; j; j /= 10 ) if( ( j % 10 ) != 4 && ( j % 10 ) != 7 ) ok = 0;
			cnt[i] = cnt[i-1] + ok;
		}
		for( int i = b; i >= a + l2; i-- ) cnt[i] -= cnt[i-l2];
		int ans = 0;
		for( int i = a; i + l1 - 1 <= b; i++ )
		{
			int brus = MAX;
			for( int j = i + l2 - 1; j < i + l1; j++ ) if( cnt[j] < brus ) brus = cnt[j];
			if( brus > ans ) ans = brus;
		}
		return ans;
	}
};
