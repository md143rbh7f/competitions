public class DengklekTryingToSleep
{
	public int minDucks( int[] ducks )
	{
		int a = 1111, b = 0;
		for( int i : ducks )
		{
			if( i < a ) a = i;
			if( i > b ) b = i;
		}
		return b - a + 1 - ducks.length;
	}
}
