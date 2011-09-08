public class FiveHundredEleven
{
	public String theWinner( int[] cards )
	{
		int n = cards.length, cnt[] = new int[512];
		boolean win[][] = new boolean[512][n+1];
		for( int i = 0; i < n; i++ )
		for( int j = 0; j < 512; j++ )
		if( ( cards[i] | j ) == j )
			cnt[j]++;
		for( int i = 0; i <= n; i++ )
			win[511][i] = true;
		for( int mem = 510; mem >= 0; mem-- )
		for( int used = n-1; used >= 0; used-- )
		for( int i = 0; i < n; i++ )
		if( ( ( mem & cards[i] ) < cards[i] || used < cnt[mem] ) && !win[mem|cards[i]][used+1] )
			win[mem][used] = true;
		return win[0][0] ? "Fox Ciel" : "Toastman";
	}
}
