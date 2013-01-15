public class PenguinTiles
{
	public int minMoves( String[] tiles )
	{
		int n = tiles.length, m = tiles[0].length();
		if( tiles[n-1].charAt( m - 1 ) == '.' ) return 0;
		for( int i = 0; i < n; i++ ) if( tiles[i].charAt( m - 1 ) == '.' ) return 1;
		for( int i = 0; i < m; i++ ) if( tiles[n-1].charAt( i ) == '.' ) return 1;
		return 2;
	}
}
