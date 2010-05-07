public class TheMoviesLevelOneDivTwo
{
	public int find( int X, int Y, int[] xtaken, int[] ytaken )
	{
		int ans = 0;
		boolean[][] taken = new boolean[X][Y];
		for( int i = 0; i < xtaken.length; i++ ) taken[xtaken[i]-1][ytaken[i]-1] = true;
		for( int i = 0; i < X; i++ )
		{
			int j = 0;
			while( j < Y )
			{
				if( taken[i][j] ) j++;
				else
				{
					int j2 = j;
					while( j2<Y && !taken[i][j2] ) j2++;
					ans += j2-j-1;
					j = j2+1;
				}
			}
		}
		return ans;
	}
}
