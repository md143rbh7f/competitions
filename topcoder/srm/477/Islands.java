public class Islands
{
	public int beachLength( String[] kingdom )
	{
		int n = kingdom.length, m = kingdom[0].length(), tot = 0;
		for( int i = 0; i < n; i++ ) for( int j = 1; j < m; j++ ) if( kingdom[i].charAt(j)!=kingdom[i].charAt(j-1) ) tot++;
		for( int i = 1; i < n; i+=2 )
		{
			for( int j = 0; j < m; j++ ) if( kingdom[i].charAt(j)!=kingdom[i-1].charAt(j) ) tot++;
			for( int j = 0; j < m-1; j++ ) if( kingdom[i].charAt(j)!=kingdom[i-1].charAt(j+1) ) tot++;
		}
		for( int i = 2; i < n; i+=2 )
		{
			for( int j = 0; j < m; j++ ) if( kingdom[i].charAt(j)!=kingdom[i-1].charAt(j) ) tot++;
			for( int j = 1; j < m; j++ ) if( kingdom[i].charAt(j)!=kingdom[i-1].charAt(j-1) ) tot++;
		}
		return tot;
	}
}
